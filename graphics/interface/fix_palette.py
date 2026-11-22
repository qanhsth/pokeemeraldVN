from PIL import Image
import math

original_file = "menu_info_org.png"
new_file = "menu_info.png"
output_file = "menu_info_fixed.png"


def get_palette_colors(img):
    palette = img.getpalette()
    colors = []

    # PIL palette contains RGB triplets
    for i in range(0, len(palette), 3):
        colors.append(tuple(palette[i:i + 3]))

    return colors


def color_distance(c1, c2):
    """Euclidean RGB distance."""
    return math.sqrt(
        (c1[0] - c2[0]) ** 2 +
        (c1[1] - c2[1]) ** 2 +
        (c1[2] - c2[2]) ** 2
    )


# --------------------------------------------------
# Load images
# --------------------------------------------------

original = Image.open(original_file).convert("P")
new = Image.open(new_file).convert("P")

original_palette = get_palette_colors(original)
new_palette = get_palette_colors(new)

print(f"Original palette: {len(original_palette)} colors")
print(f"New palette:      {len(new_palette)} colors")


# --------------------------------------------------
# Find mapping:
#
# new palette color -> closest original palette color
# --------------------------------------------------

mapping = {}

for new_index, new_color in enumerate(new_palette):
    distances = [
        color_distance(new_color, original_color)
        for original_color in original_palette
    ]

    original_index = distances.index(min(distances))

    mapping[new_index] = original_index

    print(
        f"{new_index:2}: {new_color} "
        f"-> {original_index:2}: {original_palette[original_index]} "
        f"(distance {distances[original_index]:.2f})"
    )


# --------------------------------------------------
# Replace pixel indices
# --------------------------------------------------

pixels = list(new.getdata())

fixed_pixels = [
    mapping[pixel_index]
    for pixel_index in pixels
]


# --------------------------------------------------
# Create output image
# --------------------------------------------------

output = Image.new("P", new.size)
output.putdata(fixed_pixels)


# Use the ORIGINAL palette
output.putpalette(original.getpalette())


# --------------------------------------------------
# Save
# --------------------------------------------------

output.save(output_file, optimize=False)

print()
print(f"Saved: {output_file}")
