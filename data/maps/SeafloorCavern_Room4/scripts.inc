SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Ngươi là ai?\n"
	.string "Đi đường nào vô vậy?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Thua rồi…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Ta không kiếm được đường ra!\p"
	.string "Ta không có sợ. Đừng có hiểu lầm!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Ngươi là ai?\n"
	.string "Tính đi đâu vậy?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Không thắng được!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Thằng cộng sự nó bỏ quên\n"
	.string "cái bản đồ trong tàu ngầm rồi!\p"
	.string "Sao mà vô dụng quá vậy trời?$"

