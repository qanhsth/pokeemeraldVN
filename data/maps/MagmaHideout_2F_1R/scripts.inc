MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Cái gì, cái gì, cái gì?\p"
	.string "Chỉ có thành viên ĐỘI MAGMA\n"
	.string "mới được vô đây!\p"
	.string "Ngươi không có mặc đồ\n"
	.string "của MAGMA…\p"
	.string "Ngươi quá khả nghi!\n"
	.string "Đấu với ta!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Tự hào là thành viên MAGMA vậy mà…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Nếu bị ớn lạnh, thì\n"
    .string "gia nhập ĐỘI MAGMA đi.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Khoan, chờ đó!\p"
	.string "Ngươi thiệt sự nghĩ ta sẽ câm miệng\n"
    .string "mà để ngươi ung dung đi qua sao?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
    .string "Trời ơi!\n"
    .string "Thôi thua!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
    .string "Có lẽ sẽ tốt hơn nếu ta\n"
    .string "để ngươi đi qua mà không cản trở…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "À ha!\n"
	.string "Có kẻ đột nhập!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Gừ roaaaa!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "Ta thua rồi.\p"
	.string "Ta có nên tiếp tục\n"
	.string "chạy vòng vòng để canh nữa không?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Ủa, ủa!\n"
	.string "Ai đó!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Làu bàu…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Thực ra, ta không giỏi giao chiến…$"

