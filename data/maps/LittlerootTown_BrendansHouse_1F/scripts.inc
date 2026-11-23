LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MẸ: Đó thấy chưa, {PLAYER}?\n"
	.string "Không phải trong này cũng thoái mái sao?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "POKéMON dời nhà phụ xong rồi\n"
	.string "còn quét dọn giùm mình nữa.\l"
	.string "Tiện ghê ha!\p"
	.string "{PLAYER}, phòng con ở trên lầu á.\n"
	.string "Lên coi thử đi, con!\p"
	.string "BA mới mua cho con cái đồng hồ\n"
	.string "làm quà chuyển nhà.\l"
	.string "Nhớ chỉnh giờ lại nha!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MẸ: Ủa, {PLAYER}?\p"
	.string "Con hông khoái\n"
	.string "phòng mình hả?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MẸ: {PLAYER} ơi.\p"
	.string "Đi chỉnh giờ lại đi, con.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MẸ: Ủa! {PLAYER} ơi, {PLAYER}!\n"
	.string "Lại đây mẹ biểu!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MẸ: Coi nè! NHÀ THI ĐẤU HOA CAM!\n"
	.string "Chắc chút nữa cũng có BA CON nữa đó!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MẸ: Ủa… Hết luôn rồi.\p"
	.string "Tưởng đâu BA CON có lên hình, hay là\n"
	.string "lướt qua rồi ta.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "À, đúng rồi.\n"
	.string "Bạn của BA CON sống ở đây.\p"
	.string "Ổng là TS.BÌNH.\p"
	.string "Nhà ổng kế bên đó, con đi qua\n"
	.string "chào hỏi đi.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MẸ: Đi mạnh giỏi nha con!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MẸ: Con có chào hỏi TS.BÌNH\n"
	.string "chưa?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MẸ: Sao rồi con?\n"
	.string "Nhìn uể oải quá vậy.\p"
	.string "Mẹ thấy con nên nằm nghỉ xíu đi.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MẸ: Cẩn trọng nha con!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MẸ: Ủa? BA đưa con cái HUY HIỆU đó hả?\p"
	.string "Vậy MẸ cũng có cái này cho con nè!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Đừng ép mình quá.\n"
	.string "Có gì cứ về nhà nha con.\p"
	.string "Đi đi con!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MẸ: Cái đó là gì vậy con? BẢN ĐỒ hả?\n"
	.string "Công ty DEVON đưa cho con hả?\p"
	.string "À mà, lưu số mẹ\n"
	.string "vô luôn nha.\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Đã lưu số MẸ\n"
	.string "vô BẢN ĐỒ.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Phừ gíiiii!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Hừ gô, ừ gô ừ gô…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "PHÓNG VIÊN: …Chúng tôi đang ở\n"
	.string "trước NHÀ THI ĐẤU HOA CAM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Tivi đang chiếu bộ phim.\p"
	.string "Về 2 người đàn ông đang nhảy\n"
	.string "trên cây đàn piano.\p"
	.string "Thôi kệ đi!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "Đây là hướng dẫn sử dụng\n"
	.string "GIÀY CHẠY BỘ.\p"
	.string "“Nhấn Nút B để chạy khi\n"
	.string "đang mang GIÀY CHẠY BỘ.\p"
	.string "“Thắt dây GIÀY CHẠY BỘ và\n"
	.string "chạy thôi!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "BA: Ủa?\p"
	.string "{PLAYER} hả?\p"
	.string "Lâu rồi mới thấy con,\n"
	.string "nay nhìn con…chững chạc hơn thì phải.\p"
	.string "Đúng là con của ta.\n"
	.string "Ông già mày chưa chịu thua đâu nha!\p"
	.string "À phải rồi, ba có cái này cho con.\n"
	.string "Có 1 người tên là ÔNG THU\l"
	.string "nhờ ba đưa cho con giùm.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "BA: Hửm, VÉ để đi tàu à?\p"
	.string "Nếu ba nhớ không lầm, có nhiều bến phà\n"
	.string "ở TP.CẢNG với TP.BIỂN lắm.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Thôi chắc ba quay lại NHÀ THI ĐẤU đây.\p"
	.string "Nói MẸ là ba cảm ơn vì đã coi nhà\n"
	.string "trong lúc ba đi vắng giùm nha.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MẸ: Ông BA của con…\p"
	.string "Lâu lắm rồi mới về, mà ổng\n"
	.string "toàn nói về POKéMON không à.\p"
	.string "Sao ổng không ở thêm vài bữa nữa?$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MẸ: Có tin gì chấn động nè.$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Chúng tôi có 1 tin\n"
	.string "chấn động muốn thông báo cho quý vị!\p"
	.string "Tại nhiều nơi ở HOENN, đã\n"
	.string "có báo cáo về con POKéMON\l"
	.string "có màu x... đang bay khắp nơi.\p"
	.string "Danh tính về con POKéMON này\n"
	.string "hiện chưa được làm rõ.\p"
	.string "Chúng tôi sẽ quay trở lại với\n"
	.string "chương trình truyền hình.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MẸ: Nãy người ta nói gì vậy ta?\p"
	.string "Con POKéMON đó có\n"
	.string "màu gì á?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MẸ: Kỳ lạ ha!\n"
	.string "Vẫn có POKéMON mà ta chưa biết đến.$"
