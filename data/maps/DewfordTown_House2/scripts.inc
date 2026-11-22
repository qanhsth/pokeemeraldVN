DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Hãy chiêm ngưỡng món hàng này!\p"
	.string "Đây là KHĂN LỤA. Đang dẫn\n"
	.string "đầu xu hướng thời trang đó!\p"
	.string "Mắt bạn cũng chớp chớp rồi ha!\n"
	.string "Bạn đã nhìn thấu phong cách của tui!\p"
	.string "Bạn thiệt dễ thương!\n"
	.string "Tặng bạn nè. Cầm lấy đi!$"

DewfordTown_House2_Text_NoRoom:
	.string "Ủa, không có chỗ để hả?\p"
	.string "Nghe kỹ nè, cái KHĂN này là bắt buộc\n"
	.string "phải có! Tui còn muốn bán hết đồ\l"
	.string "chỉ để có được nó thôi đó!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "KHĂN LỤA giúp tăng ST cho\n"
	.string "chiêu thức hệ THƯỜNG.\p"
	.string "Đây là một cái KHĂN ảo diệu\n"
	.string "có thể xài cho hầu hết POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, bạn mắc công vượt biển\n"
	.string "để tới THÔN ĐẢO này sao?\p"
	.string "Phải chăng bạn tới đây vì\n"
	.string "nghe người ta nói về ĐÔNG?\p"
	.string "Ảnh ngầu lắm đó…\n"
	.string "Ai cũng hâm hộ ảnh hết trơn.$"

