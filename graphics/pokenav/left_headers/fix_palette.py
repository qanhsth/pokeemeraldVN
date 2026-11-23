from PIL import Image

input_file = "condition.png"
original_file = "condition_org.png"
output_file = "condition_fixed.png"

new_img = Image.open(input_file).convert("P")
org_img = Image.open(original_file).convert("P")

# New palette index -> original palette index
mapping = {
    0:  9,   # Black
    1:  8,   # #FFEE62
    2:  1,   # #F6C531
    3:  2,   # White
    4:  10,   # #52524A
    5:  0
}

# Check that every used pixel index has a mapping
pixels = list(new_img.getdata())
missing = set(pixels) - set(mapping)

if missing:
    raise ValueError(f"Missing mappings for indices: {sorted(missing)}")

# Remap pixel indices
remapped_pixels = [mapping[index] for index in pixels]

# Create output using the original palette
output = Image.new("P", new_img.size)
output.putdata(remapped_pixels)
output.putpalette(org_img.getpalette())

# Preserve transparency if present
if "transparency" in new_img.info:
    output.info["transparency"] = new_img.info["transparency"]

output.save(output_file, format="PNG", optimize=False)

print(f"Saved: {output_file}")
print("Original palette applied with matching pixel indices.")
