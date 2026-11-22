SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Ở đây không cần con nít!\n"
	.string "Về nhà đi!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Ta muốn về nhà…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Ta muốn được thăng chức,\n"
	.string "đặng quản lý đám CULI…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Cái tàu ngầm đó… Ở trong nhỏ quá.\n"
	.string "Nhức mình quá!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
    .string "Thua trận làm ta đau nhức quá!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
    .string "Cái tàu ngầm mà tụi ta cướp được á ba,\n"
    .string "vô trong đó đúng quãi luôn ba.\l"
    .string "Kiểu trong đó chật quá á ba!$"

