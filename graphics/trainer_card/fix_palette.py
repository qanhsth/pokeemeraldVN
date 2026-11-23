from PIL import Image

input_file = "tiles.png"
original_file = "tiles_org.png"
output_file = "tiles_fixed.png"

new_img = Image.open(input_file).convert("P")
org_img = Image.open(original_file).convert("P")

# New palette index -> original palette index
mapping = {
    0:  0,   
    1:  1,  
    2:  5,   
    3:  3,   
    4:  9,   
    5:  2,
6:10,
7:11,
8:15,
9:4,
10:28,
11:12,
12:14,
13:29,
14:7,
15:13,
16:8,
17:49,
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
