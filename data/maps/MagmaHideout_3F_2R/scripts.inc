MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
    .string "Ta hiểu hết lời của thủ lĩnh nói.\n"
    .string "Nhưng mà ngươi biết không?\p"
    .string "Làm những chuyện như đào bới một con\n"
    .string "POKéMON siêu cổ, rồi ăn cắp\l"
	.string "ĐÁ TRỜI của người ta…\p"
    .string "Ta nghĩ tụi ta đang đi quá xa rồi.\n"
    .string "Ngươi nghĩ sao?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
    .string "Ừ, ta nghĩ tụi ta đang làm chuyện\n"
	.string "gì đó rất sai.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
    .string "Bị ngươi hạ gục, làm ta sáng suốt hơn.\p"
    .string "Lần sau khi gặp thủ lĩnh, ta sẽ hỏi\n"
    .string "lại ổng về chuyện mà tụi ta đang làm.$"

