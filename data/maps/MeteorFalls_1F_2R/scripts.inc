MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Đây là nơi mà người luyện RỒNG như ta\n"
	.string "huấn luyện.\p"
	.string "NHÀ VÔ ĐỊCH còn tới đây thăm.\n"
	.string "Ngươi có thấy nơi này đặc biệt chưa?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Hựưư!\n"
	.string "Không ngờ nhà ngươi mạnh vậy!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "Con đường phía trước còn dài.\p"
	.string "Tới khi nào thì POKéMON\n"
	.string "và ta mới là số một?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Ta muốn biết thêm về sức mạnh của ngươi.\n"
	.string "Hãy để ta lưu số ngươi vô BẢN ĐỒ.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Since we met, we have trained hard\n"
	.string "with our sights on number one.\p"
	.string "Help us see how much stronger we've\n"
	.string "become!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Hựưư!\n"
	.string "Không ngờ nhà ngươi mạnh vậy!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Ngươi vẫn kiên trì\n"
	.string "tập luyện POKéMON.\p"
	.string "Nếu ngươi giữ được sức mạnh của mình,\n"
	.string "thì ta, cũng sẽ trở nên mạnh như ngươi!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "CHUNG: Tụi ta thách đấu POKéMON\n"
	.string "chung với nhau như một cặp vậy.\l"
	.string "Tụi ta đều rất tự tin.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "CHUNG: Trời đất.\n"
	.string "Tụi mình thua rồi, vợ ơi.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "CHUNG: Tụi ta lấy nhau\n"
	.string "được năm chục năm rồi.\p"
	.string "Nghĩ lại thì ta chưa từng\n"
	.string "thắng được vợ mình trong trận đấu.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "CHUNG: Trời, trởi, 1 NHL trẻ tuổi!\p"
	.string "Con sẽ thách đấu với tụi ta chứ?\n"
	.string "Nếu vậy, hãy đem nhiều POKéMON hơn.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "CHUNG: NHL trẻ ơi, nếu có cơ hội,\n"
	.string "con sẽ thách đấu lại với tụi ta chứ?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "TRÂN: Tụi ta lấy nhau\n"
	.string "được năm chục năm rồi.\p"
	.string "Sợi dây tơ hồng của tụi ta\n"
	.string "không bao giờ đứt được.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "TRÂN: Trời ơi.\n"
	.string "Tụi mình thua rồi, chồng ơi.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "TRÂN: 50 năm lấy nhau…\p"
	.string "Nếu có cãi nhau, tụi ta\n"
	.string "sẽ quyết thắng thua bằng POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "TRÂN: Trời, trởi, 1 NHL trẻ tuổi\n"
	.string "đây sao?\p"
	.string "Nếu con muốn thách đấu với tụi ta,\n"
	.string "hãy đem nhiều POKéMON hơn.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "CHUNG: Tụi ta thách đấu POKéMON\n"
	.string "chung với nhau như một cặp vậy.\l"
	.string "Tụi ta đều rất tự tin.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "CHUNG: Trời đất.\n"
	.string "Tụi mình thua rồi, vợ ơi.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "CHUNG: Lấy nhau 50 năm…\p"
	.string "Ngẫm lại thì, vợ với tui, đã cùng nhau\n"
	.string "thách đấu quanh năm suốt tháng…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "CHUNG: Trời, trởi, 1 NHL trẻ tuổi!\p"
	.string "Con sẽ thách đấu với tụi ta chứ?\n"
	.string "Nếu vậy, hãy đem nhiều POKéMON hơn.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "TRÂN: Tụi ta lấy nhau\n"
	.string "được 50 năm rồi.\p"
	.string "Tụi ta đều giúp đỡ lẫn nhau.\n"
	.string "Cả 2 người tụi ta đều cùng mạnh.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "TRÂN: Trời ơi.\n"
	.string "Tụi mình thua rồi, chồng ơi.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "TRÂN: 50 năm lấy nhau…\n"
	.string "Có nhiều chuyện xảy ra.\p"
	.string "Tui mong rằng tụi mình sẽ tiếp\n"
	.string "tục tạo ra kỷ niệm đẹp cho nhau.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "TRÂN: Trời, trởi, 1 NHL trẻ tuổi\n"
	.string "đây sao?\p"
	.string "Nếu con muốn thách đấu với tụi ta,\n"
	.string "hãy đem nhiều POKéMON hơn.$"

