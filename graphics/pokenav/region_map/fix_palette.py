from PIL import Image

input_file = "city_zoom_text.png"
original_file = "city_zoom_text_org.png"
output_file = "city_zoom_text_new.png"

new_img = Image.open(input_file).convert("P")
org_img = Image.open(original_file).convert("P")

# New palette index -> original palette index
mapping = {
    0:  0,   # Black -> black
    1:  3,   # #FF4141
    2:  5,   # #1010FF
    3: 15,   # #CD8352
    4:  2,   # #FF8300
    5:  4,   # #839CF6
}

# Remap pixel indices
pixels = list(new_img.getdata())

missing = set(pixels) - set(mapping)
if missing:
    raise ValueError(f"Missing mappings for indices: {sorted(missing)}")

remapped_pixels = [mapping[index] for index in pixels]

# Create output with the original palette
output = Image.new("P", new_img.size)
output.putdata(remapped_pixels)
output.putpalette(org_img.getpalette())

# Preserve transparency metadata, if present
if "transparency" in new_img.info:
    output.info["transparency"] = new_img.info["transparency"]

output.save(output_file, format="PNG", optimize=False)

print(f"Saved: {output_file}")
print("Original palette copied and pixel indices remapped.")
