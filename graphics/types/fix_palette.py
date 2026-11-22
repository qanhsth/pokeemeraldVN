from PIL import Image

input_file = "normal.png"
input_org_file = "normal_org.png"
output_file = "normal_fixed.png"

img = Image.open(input_file).convert("P")
org = Image.open(input_org_file).convert("P")

# New palette index -> original palette index
mapping = {
    0: 0,
    1: 9,
    2: 8,
    3: 15,
    4: 14,
    5: 10
}

# Remap pixels
pixels = [mapping[p] for p in img.getdata()]
img.putdata(pixels)

# Copy the EXACT palette from the original image
original_palette = org.getpalette()
img.putpalette(original_palette)

# Save
img.save(output_file)

print("Saved:", output_file)
