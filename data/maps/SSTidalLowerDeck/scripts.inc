SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Aaặcccc! Dọn cái chỗ này riết\n"
	.string "mệt với chán quá!\p"
	.string "Làm một trận nhanh nè!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Em trai ơi, ta thua rồi!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Tụi tui là ANH EM DỌN PHÒNG!\p"
	.string "Thằng anh thì đổ xà bông,\n"
	.string "còn thằng em thì chà rửa!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Đây là phần đáy thân tàu.\n"
    .string "Ở đây rất rộng rãi.\l"
    .string "Rất thích hợp cho một trận đấu POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Anh trai ơi, em thua rồi!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Tụi tui là ANH EM DỌN PHÒNG!\p"
	.string "Thằng anh thì đổ xà bông,\n"
	.string "còn thằng em thì chà rửa!$"

