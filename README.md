# Pokémon Emerald Việt Hoá
>Dịch từ code của [pret](https://github.com/pret/pokeemerald).

- Đây là bản dịch theo tiếng Nam Kỳ, những khu vực lân cận Sài Gòn. 
- Mình làm project này, mục đích để giúp đỡ cộng đồng.
Mình sẽ viết đầy đủ cách làm trong project này để người sau còn biết mà làm lại.
Ai thấy cách làm không hay, làm ơn chỉ lại mình giùm.
 
## TRONG NÀY CÓ GÌ?
- Dịch toàn bộ những gì có thể dịch ra tiếng Việt.
Những cái quá khó, thí dụ: hiệu ứng `PSN`, chữ quá nhỏ sẽ không dịch.
- Tự tay dịch, không xài AI, nên sẽ có *sai*.
- Ngôn từ bảo đảm phù hợp cho trẻ em 10 tuổi, giống như game đề ra.
- Sửa code ở mấy chỗ: 
1. Sửa preffix -> suffix ở chỗ gặp wild POKéMON trong phần battle_message.c.
2. Sửa 1 xíu code để thêm bàn phím tiếng Việt ở naming_screen.c.
3. Đổi thành suffix cho loại POKéMON ở international_string_util.c. 
4. Kéo dài limit cho TRAINER_NAME, HỆ ở cảnh chọn chiêu đánh, v.v.

Còn nữa, mỗi file sẽ có chú thích sửa gì trong đó.
## MỤC LỤC
[1. TẢI GAME](#1-tải-game)

[2. CÁCH EDIT HÌNH](#2-cách-edit-hình)

[3. CÁCH EDIT FONT](#3-cách-edit-font)

[4. GIỚI HẠN KÝ TỰ](#4-giới-hạn-ký-tự)

[5. TỰ BUILD GAME](#5-tự-build-game)

### 1. TẢI GAME
- Trong phần Release.
- Khi hoàn chỉnh hết, sẽ up lên archieve

**Lưu ý khi cập nhật**

Khi muốn cập nhật lên bản mới mà không muốn bị mất dữ liệu.
- Lúc save game, đừng có lưu `state` mà hãy lưu bằng nút `LƯU` ở trong game.

File lưu nó sẽ có dạng kiểu `emerald.sav`.

Còn file state thì `emerald.ss1`.
- File save phải giống file game.

Thí dụ, 
File game: `emerald.gba`

File save: `emerald.sav`
- File game và file save phải ở chung 1 folder.

Thí dụ:
Folder game: /game/emerald.gba
Folder save: /game/emerald.sav
### 2. CÁCH EDIT HÌNH
- Hình ở trong game này là pixel. Nên là xài mấy app như picsart để photoshop không được đâu.
- Muốn edit, phải có phần mềm hỗ trợ pixel.

Ở đây, mình xài [Piskel](https://www.piskelapp.com/p/create/sprite).
> Đây là cách mà mình làm, ai có cách hay hơn, thì chỉ lại giùm.

- **Bước 1**, sửa và tải hình về, ở trên [Piskel](https://www.piskelapp.com/p/create/sprite).

Lúc này hình đang ở dạng `RGB`, mà game thì chỉ support kiểu `colormap` (gameboy color).
Nên là code sẽ báo lỗi.
- **Bước 2**, tải [Gimp](https://www.gimp.org/downloads) về.

Import hình muốn sửa vô.

Kiếm tab `Image`, bấm vô chọn `Mode` -> `Indexes`.

`Maximum number...` tuỳ theo hình mà có số màu khác nhau, để đại 100 cũng được.

Sau đó `Convert` rồi export ra.
Lúc này, file hình tự nhiên quá lớn, gần như x2 dung lượng.
- **Bước 3**, tải [ImageMagick](https://imagemagick.org/download/#gsc.tab=0) về.

Chạy câu lệnh trên cmd như sau để giảm dung lượng:
```
convert abc.png -strip abc1.png
```

Lúc này, mọi thứ dường như đã xong, **nhưng** màu bị *đổi chỗ*!?

Thí dụ, chỗ đó trên hình màu *trắng* mà trong game lại hiện màu *xám*?!

Bắt buộc phải check lại hình mới và hình gốc:
```
identify -verbose abc1.png
identify -verbose abc_org.png
```

Chỉ check phần `Colormap`, tại vì nó chỉ bị *đổi chỗ* cái màu thôi.

Thí dụ phần `Colormap`, file mới thì vị trí 0 là màu trắng.
```
Colormap:
0: (255,255,255) #FFFFFF white
```
Còn file cũ thì, vị trí 3 mới là trắng.
```
Colormap:
3: (255,255,255) #FFFFFF white
```
- **Bước 4**, làm 1 cái script python để sửa lại hình.

Ở trong mỗi folder hình, mình có để 1 file minh hoạ là `fix_pallete.py`.

Cứ soi từng màu, coi chỗ nào không khớp thì sửa lại.

>Cái này kêu ChatGPT nó viết giùm cũng được.

Chạy cái file đó xong là hình không còn lỗi nữa.

### 3. CÁCH EDIT FONT
Game này không có bảng chữ cái tiếng Việt, nên phải tự thêm vô.
Tại vì là bảng chữ tiếng Anh + tiếng Nhật chiếm hết chỗ nên,
tiếng Việt phải thêm cuối bảng với 2 `bit` 1 ký tự !?

-> Thí dụ, coi trong file charmap.txt

Chữ `A` trong trong tiếng Anh gán cho `bit` `01`.

-> 1 `bit`

Chữ `Ả` tự thêm vô gán cho `bit` `F9 20`.

-> 2 `bit`

Có nghĩa là trong 1 số trường hợp sẽ bị giới hạn ký tự, tại vì
1 chữ tiếng Việt = 2 chữ tiếng Anh

-> Nếu mà bỏ được mấy chữ latin như ç thì sẽ fix được, tại vì
không biết là bỏ có được không nên cái này sẽ *fix* sau.

Để sửa lại font, thì cần phải sửa mấy file kiểu latin_normal, latin_short, v.v.

Có bảng dưới để tham khảo chức năng của mỗi file, cũng như chỗ cần sửa:

|  | Sử dụng trong |
| ----------- | ----------- |
| latin_normal | Gần như toàn bộ từ thoại tới mô tả, v.v. |
| latin_short | Tên skill lúc giao chiến, mô tả nhỏ trong TÚI, v.v. |
| latin_small | Chữ trên thanh máu, tên POKéMON trong tổ đội, v.v.  |
| latin_narrow | Bảng thông báo tới thị trấn mới | 
| latin_small_narrow | Mô tả trong điện thoại |

>Sửa xong file hình, nhớ vô fonts.c sửa lại kích cỡ ô chữ.
### 4. GIỚI HẠN KÝ TỰ
Câu thoại sẽ bị mất chữ, hay đúng hơn là không thấy chữ ở sau, do bị giới hạn ký tự.

Game này có khung cố định sẵn chứ không responsive như web đâu. 

|  | Giới hạn (ký tự) hàng ngang |
| ----------- | ----------- |
| Thoại | 40 (có thể lên tới 41 nếu chữ nhỏ) |
| Bảng thông báo thị trấn | 14 |
| Mô tả POKéMON trong POKéDEX | 49 |
| Mô tả item trong TÚI, shop, v.v. | 19 |
| Mô tả SKILL| 27 (có thể lên tới 28 nếu chữ nhỏ) |
| Tên SKILL | 10 (có thể ít hơn do 1 chữ Việt = 2 `bit`) |
| Tên TRAINER | 13 |
### 5. TỰ BUILD GAME
- Làm giống như các bước bên [pret](https://github.com/pret/pokeemerald/blob/master/INSTALL.md).
- Sau đó, clone `code` mình về rồi copy qua thôi.
```
git clone https://codeberg.org/toilaqanh/POKEMON-EMERALD-VIETNAMESE.git
cp -a POKEMON-EMERALD-VIETNAMESE/. pokeemerald/
```