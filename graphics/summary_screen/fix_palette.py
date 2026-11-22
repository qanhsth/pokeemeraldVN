from PIL import Image
from collections import defaultdict, Counter

input_file = "tiles.png"
original_file = "tiles_org.png"
output_file = "tiles_fixed.png"

# Open as indexed images
img = Image.open(input_file).convert("P")
original = Image.open(original_file).convert("P")

if img.size != original.size:
    raise ValueError("Images must have the same dimensions!")

# ---------------------------------------------------------
# Get palettes
# ---------------------------------------------------------

new_palette = img.getpalette()
original_palette = original.getpalette()

# Make sure palettes contain 128 entries (384 values)
new_palette = new_palette[:128 * 3]
original_palette = original_palette[:128 * 3]

# ---------------------------------------------------------
# Find:
#
#     NEW palette index -> ORIGINAL palette index
#
# by comparing the same pixel positions.
# ---------------------------------------------------------

mapping_votes = defaultdict(Counter)

new_pixels = list(img.getdata())
original_pixels = list(original.getdata())

for new_index, original_index in zip(new_pixels, original_pixels):
    mapping_votes[new_index][original_index] += 1

# ---------------------------------------------------------
# Build mapping
# ---------------------------------------------------------

mapping = {}

print("Palette mapping:")
print("----------------")

for new_index in sorted(mapping_votes):

    original_index, count = mapping_votes[new_index].most_common(1)[0]

    total = sum(mapping_votes[new_index].values())
    confidence = count / total * 100

    mapping[new_index] = original_index

    print(
        f"{new_index:3} -> {original_index:3} "
        f"({confidence:6.2f}%)"
    )

# ---------------------------------------------------------
# Remap pixel indexes
# ---------------------------------------------------------

pixels = [
    mapping[p]
    for p in new_pixels
]

img.putdata(pixels)

# ---------------------------------------------------------
# Use ORIGINAL palette
# ---------------------------------------------------------

img.putpalette(original_palette)

# ---------------------------------------------------------
# Save
# ---------------------------------------------------------

img.save(output_file)

print()
print("Saved:", output_file)
