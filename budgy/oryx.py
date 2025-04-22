import re

def convert_to_array(keymap_str):
    # This regex splits on commas that are not inside parentheses
    pattern = r',(?![^(]*\))'
    tokens = re.split(pattern, keymap_str)
    return [token.strip() for token in tokens if token.strip()]

# Define a function to process the entire keymap structure
def get_layer_array(content, layer):
    # Manually extract the keymap part from the input code
    keymap_start = content.find(f"[{layer}] = LAYOUT_moonlander(")
    keymap_end = content.find("  ),\n", keymap_start)
    
    # Extract the keymap string (everything between the start and end markers)
    keymap_str = content[keymap_start + len(f"[{layer}] = LAYOUT_moonlander("):keymap_end].strip()
    return convert_to_array(keymap_str)


def count_moonlander_layer(content):
    """Counts the occurrences of '[*] = LAYOUT_moonlander(' in the given content."""
    return len(re.findall(r'\[\d+\] = LAYOUT_moonlander\(', content))


def convert_to_budgy_layout(content):
    # Define the indices that match the 34 keys you want for Budgy
    budgy_key_indices = [
        15, 16, 17, 18, 19,    22, 23, 24, 25, 26,
        29, 30, 31, 32, 33,    36, 37, 38, 39, 40,
        43, 44, 45, 46, 47,    48, 49, 50, 51, 52,
                    66, 67,    70, 71
    ]

    # Extract the desired keys using array indexing
    budgy_keys = [content[i] for i in budgy_key_indices]

    return budgy_keys

def generate_keymap(keymap_2d):
    # Start the structure for the keymaps array
    result = "const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {\n"

    # Iterate through each layer in the 2D array
    for layer_num, layer in enumerate(keymap_2d):
        result += f"  [{layer_num}] = LAYOUT_split_3x5_2(\n"
        
        # For each row in the layer, iterate and add the key values
        for i, row in enumerate(layer):
            result += f"{row}"
            if i < len(layer) - 1:  # Add a comma after each row except the last one
                result += ", "
        
        result += "),\n"

    # End the structure for the keymaps array
    result += "};\n"

    return result

def read_keymap_file():
    with open('34RRD/keymap.c', 'r') as file:
        return file.read()

def replace_keymaps_block(original_content: str, new_keymaps_str: str):
    start = end = None
    lines = original_content.splitlines()

    for i, line in enumerate(lines):
        if 'const uint16_t PROGMEM keymaps' in line:
            start = i
        if start is not None and '};' in line:
            end = i
            break

    if start is not None and end is not None:
        # Replace entire block with new content
        new_content = "\n".join(lines[:start]) + "\n" + new_keymaps_str.strip() + "\n" + "\n".join(lines[end + 1:])
        return new_content
    else:
        print("❌ Couldn't find the keymaps block.")
        return original_content  # Return original if no block is found

def remove_code_block(content: str, start_pattern: str) -> str:
    lines = content.splitlines()
    start = end = None
    brace_level = 0
    in_block = False

    for i, line in enumerate(lines):
        if not in_block and re.search(start_pattern, line):
            start = i
            in_block = True
            brace_level += line.count('{') - line.count('}')
            if brace_level <= 0:
                end = i
                break
            continue

        if in_block:
            brace_level += line.count('{') - line.count('}')
            if brace_level <= 0:
                end = i
                break

    if start is not None and end is not None:
        del lines[start:end + 1]
        print(f"🧽 Removed block starting with: {start_pattern}")
    else:
        print(f"⚠️ Could not find block: {start_pattern}")

    return "\n".join(lines)


def remove_single_line(content: str, line_pattern: str) -> str:
    lines = content.splitlines()
    new_lines = [line for line in lines if not re.search(line_pattern, line)]
    if len(new_lines) != len(lines):
        print(f"🧹 Removed line matching: {line_pattern}")
    return "\n".join(new_lines)






def main():
    moonlander_keymap = read_keymap_file()
    nbr_of_layers= count_moonlander_layer(moonlander_keymap)
    keymap_array = []

    for layer in range(nbr_of_layers):
        layer_array = get_layer_array(moonlander_keymap, layer)
        budgy_array = convert_to_budgy_layout(layer_array)
        keymap_array.append(budgy_array)

    budgy_keymap = ""
    if keymap_array:
        budgy_keymap = generate_keymap(keymap_array)
    new_layout = replace_keymaps_block(moonlander_keymap, budgy_keymap)


    without_rgb = remove_code_block(new_layout, r'void set_layer_color\(int layer\)')
    without_rgb = remove_code_block(without_rgb, r'bool rgb_matrix_indicators_user\(void\)')
    without_rgb = remove_code_block(without_rgb, r'const uint8_t PROGMEM ledmap\[\]\[RGB_MATRIX_LED_COUNT\]\[3\] = {')
    #without_rgb = remove_code_block(without_rgb, r'case RGB_SLD:')

    # Remove single lines
    without_rgb = remove_single_line(without_rgb, r'rgb_matrix_enable\(\);')
    without_rgb = remove_single_line(without_rgb, r'extern rgb_config_t rgb_matrix_config;')


    
    pattern = r"(case\s+RGB_SLD:.*?)(?:\n.*?){8}"

    final_layout = re.sub(pattern, "", without_rgb, flags=re.DOTALL)

    print(final_layout)


if __name__ == "__main__":
    main()
