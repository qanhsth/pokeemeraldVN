from PIL import Image

input_file = "hoenn_map.png"
original_file = "hoenn_map_org.png"
output_file = "hoenn_map_fixed.png"

new_img = Image.open(input_file).convert("P")
org_img = Image.open(original_file).convert("P")

# New palette index -> original palette index
mapping = {
    0:  0,   # Black
    1:  5,   # #FFEE62
    2:  4,   # #F6C531
    3:  1,   # White
    4:  2,   # #52524A
    5:  10,
6:8,
7:6
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
