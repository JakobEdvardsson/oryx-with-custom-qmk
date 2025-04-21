import re

def convert_to_array(keymap_str):
    keys = keymap_str.split(',')
    return [key.strip() for key in keys if key.strip()]

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
        29, 30, 31, 32, 33,    34, 35, 36, 37, 38,
        41, 42, 43, 44, 45,    48, 49, 50, 51, 52,
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

input_code = """
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_Q,           LT(6,KC_W),     LT(5,KC_F),     LT(4,KC_P),     LT(7,KC_B),     KC_NO,                                          KC_NO,          KC_J,           KC_L,           KC_U,           MT(MOD_RALT, KC_Y),TD(DANCE_0),    KC_NO,          
    KC_NO,          MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LSFT, KC_T),KC_G,           KC_NO,                                                                          KC_NO,          KC_M,           MT(MOD_LSFT, KC_N),MT(MOD_LCTL, KC_E),MT(MOD_LALT, KC_I),MT(MOD_LGUI, KC_O),KC_NO,          
    KC_NO,          LT(2,KC_Z),     KC_X,           KC_C,           LT(8,KC_D),     KC_V,                                           KC_K,           LT(8,KC_H),     TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    LT(3,KC_SPACE), KC_LEFT_SHIFT,  KC_NO,                          KC_NO,          MO(1),          KC_BSPC
  ),
 [1] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_Q,           LT(6,KC_W),     LT(5,KC_F),     LT(4,KC_P),     LT(7,KC_B),     KC_NO,                                          KC_NO,          KC_J,           KC_L,           KC_U,           MT(MOD_RALT, KC_Y),TD(DANCE_0),    KC_NO,          
    KC_NO,          MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LCTL, KC_S),MT(MOD_LSFT, KC_T),KC_G,           KC_NO,                                                                          KC_NO,          KC_M,           MT(MOD_LSFT, KC_N),MT(MOD_LCTL, KC_E),MT(MOD_LALT, KC_I),MT(MOD_LGUI, KC_O),KC_NO,          
    KC_NO,          LT(2,KC_Z),     KC_X,           KC_C,           LT(8,KC_D),     KC_V,                                           KC_K,           LT(8,KC_H),     TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    LT(3,KC_SPACE), KC_LEFT_SHIFT,  KC_NO,                          KC_NO,          MO(1),          KC_BSPC
  ),
};
"""

def main():
    nbr_of_layers= count_moonlander_layer(input_code)
    keymap_array = []

    for layer in range(nbr_of_layers):
        layer_array = get_layer_array(input_code, layer)
        budgy_array = convert_to_budgy_layout(layer_array)
        keymap_array.append(budgy_array)

    if keymap_array:
        print(keymap_array)
        print("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
        print(generate_keymap(keymap_array))

if __name__ == "__main__":
    main()
