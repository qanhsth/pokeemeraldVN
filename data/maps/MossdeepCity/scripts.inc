MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "ĐẠI cho tui cái này, mà\n"
	.string "không biết xài sao.\p"
	.string "Cái này kêu là ĐÁ VUA.\n"
	.string "Bạn lấy không, tui cho?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Sao bạn lại muốn lấy hả?\n"
	.string "Sao bạn kỳ vậy?\p"
	.string "Bạn có thể lấy, mà đừng\n"
	.string "có nói cho ĐẠI biết.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "Nhà của ĐẠI ở đằng kia kìa!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Ừa, thấy chưa!? Bạn tính làm gì\n"
	.string "với cục đá kỳ quặc đó?$"

MossdeepCity_Text_WailmerWatching:
	.string "Ở vòng vòng khu XANH RÊU này,\n"
	.string "bạn có thể thấy WAILMER hoang.\p"
	.string "Kêu là, ờ…\n"
	.string "Gì ta…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER canh gác!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "TRUNG TÂM VŨ TRỤ trên đảo vừa mới\n"
	.string "phóng cái tên lửa lớn lắm.\p"
	.string "Có một vụ náo loạn xảy ra, có\n"
	.string "liên quan tới lá thơ mà họ vừa nhận.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "TRUNG TÂM VŨ TRỤ trên đảo vừa mới\n"
	.string "phóng cái tên lửa lớn lắm.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Tui nghe cái ông THUỶ THỦ nói là\n"
	.string "ĐỘI AQUA mới mở cửa hàng ở TP.BIỂN.\p"
	.string "Tui cũng nghe nói là có người đi\n"
	.string "theo để lau sàn giùm họ!\p"
	.string "Mà XANH RÊU ở đây thì bị\n"
	.string "ĐỘI MAGMA nhắm tới.\p"
	.string "Nếu muốn biết họ tính làm gì,\n"
	.string "thì hãy tới TRUNG TÂM VŨ TRỤ đi.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Tui là THUỶ THỦ, tất nhiên là\n"
	.string "biển còn quan trọng hơn tui nữa.\p"
	.string "Mà bạn biết không? Lúc mà tui quay lại\n"
	.string "bờ sau chuyến đi dài, lòng tui nhẹ đi!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Có phải rất tuyệt vời?\p"
	.string "Nếu cả thế giới ngập tràn cây cỏ\n"
	.string "và bông hoa như cái đảo này?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Mọi sinh vật cần biển để tồn tại,\n"
	.string "cho dù đất liền mới là nơi sống.\p"
	.string "Cuộc đời, sau khi đi hết chặng đường,\n"
    .string "biến thành đất và về lại với đất liền.\p"
    .string "Và biển thì luôn\n"
    .string "gắn bó với đất liền.\p"
    .string "Đúng vậy, giống như bờ biển nơi đây.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Đi du ngoạn trên tàu cũng được.\p"
    .string "Mà vượt biển cùng POKéMON\n"
    .string "bằng chiêu LƯỚT SÓNG…\p"
    .string "Đó mới là một chuyến đi thú vị!\n"
    .string "Đúng không, người trẻ?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Cục đá này có ý nghĩa đặc biệt\n"
	.string "với người ở TRUNG TÂM VŨ TRỤ.\p"
	.string "Họ để đây đặng cầu mong cho\n"
	.string "tên lửa được phóng đi bình an.\p"
	.string "Khi muốn ước gì đó, bạn sẽ làm gì?\n"
	.string "Ước ông sao hả?\p"
	.string "Tui thì xài thẻ nguyện ước.\n"
	.string "Tui hay làm vậy đó.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "Đây là cục đá màu trắng.$"

MossdeepCity_Text_GymSign:
	.string "NHÀ THI ĐẤU TP.XANH RÊU\n"
	.string "LEADERS: LIZA & TATE\p"
	.string "“Sự kết hợp thần bí!”$"

MossdeepCity_Text_CitySign:
	.string "TP.XANH RÊU\n"
	.string "“Câu cửa miệng: Yêu lấy POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "TRUNG TÂM VŨ TRỤ XANH RÊU\n"
	.string "“Nơi gần nhất để tới vũ trụ.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SƠN: {PLAYER} ơi, khoẻ không con?\n"
	.string "Chú thì vẫn khoẻ!\p"
	.string "Nghe nói CHỦ GYM XANH RÊU cũng\n"
	.string "khá là mạnh, nên chú mới quyết\l"
	.string "định tới để coi tận mắt.\p"
	.string "Nhưng mà có gì đó không ổn\n"
	.string "về cái thành phố này.\p"
	.string "Người ta đang bàn tán về cái lá\n"
	.string "thơ với TRUNG TÂM VŨ TRỤ…\p"
	.string "Nhưng mà cái đó cũng đâu tới\n"
	.string "mức mà phải bàn vậy đâu, ha.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… Cảm giác sóng đánh vô\n"
	.string "chưn, sướng quá đi…\p"
	.string "Nói tới sóng thì, bạn có biết\n"
	.string "thành phố trên đảo LƯU NIẾT không?\p"
	.string "Hình như NHÀ THI ĐẤU ở đó\n"
	.string "vừa mới có CHỦ mới.\p"
	.string "Người ta nói với tui là cái\n"
	.string "người CHỦ đó từng dạy cho HẢI LY.$"

