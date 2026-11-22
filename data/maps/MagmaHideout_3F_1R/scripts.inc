MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Ta đã làm gì để bị\n"
	.string "kêu đứng đây gác vậy nè?\p"
	.string "Tai trái nóng quá!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Nóng quá, sắp xỉu tới nơi…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Ngươi có thấy kỳ khi tụi ta lại đội\n"
    .string "nón trùm đầu ở trong núi lửa này?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Tụi ta gia nhập để giúp thủ lĩnh hiện\n"
    .string "thực hóa tầm nhìn tuyệt vời của ổng.\p"
    .string "Ta không quan tâm ngươi có thuộc ĐỘI\n"
    .string "AQUA hay chỉ là đứa nhóc đi ngang qua.\p"
	.string "Không ai cản trở tụi ta mà\n"
    .string "thoát được!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Trời, đất!\n"
	.string "Ngươi không tin ta sao!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Nói nghe nè.\n"
	.string "ĐỘI MAGMA làm đúng đó!\p"
	.string "Đừng có nghe lời tụi AQUA.\n"
	.string "Tụi nó xạo đó!$"

