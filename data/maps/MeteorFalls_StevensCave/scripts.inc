MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "ĐẠI: Trời ơi, {PLAYER}.\n"
	.string "Sao kiếm được tui hay vậy.\p"
	.string "Bạn có, mm… nghĩ tui chỉ là\n"
	.string "người mê đá?\p"
	.string "Không, không phải vậy đâu.\p"
	.string "Tụi mình đã cùng nhau thách đấu\n"
	.string "ở TRUNG TÂM VŨ TRỤ LƯU NIẾT.\p"
	.string "Bạn phải có ký ức đẹp\n"
	.string "về tui chứ.\p"
	.string "Rồi, {PLAYER}, nếu bạn tính thách đấu\n"
	.string "nghiêm túc với tui, thì chuẩn bị đi!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Bạn…\n"
	.string "Không thể nào ngờ bạn mạnh tới mức này…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "ĐẠI: Nghĩ lại thì, kể từ lúc\n"
	.string "tụi mình lướt qua nhau ở HANG ĐÁ\l"
	.string "ở THÔN ĐẢO, tui đã có cảm giác này rồi.\p"
	.string "Tui còn nghĩ là bạn sẽ\n"
	.string "trở thành NHÀ VÔ ĐỊCH mà thôi.\p"
	.string "Tui hay đoán đúng lắm.\p"
	.string "Mà giờ bạn sẽ đi đâu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, tui đành bó tay thôi.$"

