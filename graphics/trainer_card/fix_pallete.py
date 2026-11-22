from PIL import Image

input_file = "tiles.png"
original_file = "tiles_org.png"
output_file = "tiles_fixed.png"


# --------------------------------------------------
# Load images
# --------------------------------------------------

new_img = Image.open(input_file).convert("P")
original_img = Image.open(original_file).convert("P")

new_palette = new_img.getpalette()
original_palette = original_img.getpalette()


def rgb(palette, index):
    return tuple(palette[index * 3:index * 3 + 3])


# --------------------------------------------------
# New tiles.png palette
# --------------------------------------------------

new_colors = [
    rgb(new_palette, i)
    for i in range(len(new_palette) // 3)
]


# --------------------------------------------------
# Original tiles_org.png palette
# --------------------------------------------------

original_colors = [
    rgb(original_palette, i)
    for i in range(len(original_palette) // 3)
]


# --------------------------------------------------
# Explicit mapping:
#
# tiles.png palette index -> tiles_org.png
# palette index
# --------------------------------------------------

mapping = {
    0: 48,   # (144,91,114) -> (139,98,115)
    1: 1,    # white -> white
    2: 32,   # (100,95,115) -> (98,98,115)
    3: 35,   # (163,163,163) -> (164,164,164)

    4: 9,    # (108,255,124) -> (180,230,156)
    5: 2,    # (221,255,220) -> (230,255,222)
    6: 10,   # (88,239,108) -> (148,238,131)
    7: 11,   # (160,243,151) -> (131,222,115)

    8: 15,   # black -> black
    9: 4,    # (122,122,122) -> (123,123,123)

    10: 28,  # (99,176,214) -> (106,180,213)
    11: 12,  # (8,186,69) -> (82,172,74)

    12: 14,  # (204,204,204) -> (205,205,205)

    13: 29,  # (40,117,165) -> (41,123,164)
    14: 7,   # (58,101,140) -> (57,106,139)

    15: 13,  # (107,177,255) -> (106,189,255)
    16: 8,   # (70,128,199) -> (65,139,197)

    17: 49,  # (244,207,0) -> (246,197,0)
}


# --------------------------------------------------
# Print mapping for verification
# --------------------------------------------------

print("Palette mapping:")
print()

for new_index, original_index in mapping.items():

    print(
        f"{new_index:2}: {new_colors[new_index]}"
        f"  ->  "
        f"{original_index:2}: {original_colors[original_index]}"
    )


# --------------------------------------------------
# Remap image pixels
# --------------------------------------------------

pixels = list(new_img.getdata())

fixed_pixels = []

for pixel_index in pixels:

    if pixel_index not in mapping:
        print(
            f"WARNING: palette index {pixel_index} "
            f"has no mapping!"
        )

        # Keep the original index as fallback
        fixed_pixels.append(pixel_index)

    else:
        fixed_pixels.append(mapping[pixel_index])


# --------------------------------------------------
# Create output
# --------------------------------------------------

output = Image.new("P", new_img.size)

output.putdata(fixed_pixels)

# IMPORTANT:
# Use the ORIGINAL palette.
output.putpalette(original_palette)


# --------------------------------------------------
# Save
# --------------------------------------------------

output.save(
    output_file,
    format="PNG",
    optimize=False
)

print()
print(f"Saved: {output_file}")
