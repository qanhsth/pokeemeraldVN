MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
    .string "Khi được triệu tập, MAGMA tụi ta sẽ\n"
    .string "nhận nhiệm vụ canh gác quan trọng theo\l"
    .string "thứ tự xếp hàng.\p"
    .string "Lý giải tại sao ta lại bị kẹt ở góc này.\n"
	.string "Ta lúc nào cũng tới trễ hơn mấy đứa kia!$"

MagmaHideout_1F_Text_Grunt1Defeat:
    .string "Mấy buổi tập huấn, ta cũng\n"
    .string "tới trễ nữa!\p"
    .string "Ta không muốn nhận, mà ta yếu thiệt…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
    .string "Được rồi, từ giờ trở đi ta sẽ\n"
    .string "nỗ lực hơn một chút…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Ông trùm biểu tụi ta đào tới\n"
	.string "NÚI LỬA, nên tụi ta cứ đào đi đào lại.\p"
	.string "Và rồi trong lúc đào, tụi ta tình cờ\n"
    .string "phát hiện ra một thứ cực khủng!\p"
    .string "Đó là gì vậy ta?\p"
    .string "Fuhahaha!\n"
    .string "Nếu hạ được ta, thì ta kể cho nghe!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh!\n"
	.string "Bị hạ rồi!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Ta không kể đâu.\n"
	.string "Cứ đi tới đó là biết thôi!\p"
	.string "Sẽ tốt hơn nếu bí mật được giữ\n"
	.string "tới phút cuối, đúng chưa?$"

