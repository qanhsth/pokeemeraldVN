MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
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

MauvilleCity_Movement_ScottExitEast:
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

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "CHÚ: Chính nhờ POKéMON mà cậu bé này\n"
    .string "có vẻ hăng hái hơn, ta nghĩ vậy…\l"
    .string "Nhưng cậu ta hơi hăng hái quá rồi…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "QUÝ: Đi mà, CHÚ, nha CHÚ?\p"
	.string "Con muốn thách đấu GYM này để coi\n"
	.string "con đã mạnh hơn bao nhiêu rồi.\p"
	.string "Nha? Nha CHÚ?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "CHÚ: Từ từ, QUÝ ơi.\p"
	.string "Từ lúc con sống với POKéMON,\n"
	.string "con đã mạnh lên rất nhiều rồi.\p"
	.string "Nhưng mà con không nghĩ là\n"
	.string "con đang ép mình để thách đấu GYM sao?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "QUÝ: Con không có tự ép mình.\p"
	.string "Chỉ cần có RALTS,\n"
	.string "tụi con có thể đánh bại bất kỳ ai!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "QUÝ: Ủa! Chào {PLAYER}!\p"
	.string "Tui đã mạnh hơn nhiều kể từ\n"
	.string "hồi tụi mình gặp rồi nè.\p"
	.string "{PLAYER} ơi, tui muốn bạn với CHÚ\n"
	.string "hiểu cho tui.\p"
	.string "{PLAYER} ơi, phiền bạn thách đấu\n"
	.string "với tui một trận được không?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "QUÝ: Trời… Nếu bạn không chịu đấu,\n"
	.string "thì CHÚ tui sẽ không công nhận là\l"
	.string "tui đã mạnh lên đâu, {PLAYER} ơi.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "CHÚ: {PLAYER} phải không?\n"
	.string "Thay mặt QUÝ, ta có thể xin con đấu\l"
    .string "với nó chỉ lần này thôi được không?\p"
    .string "Ta không nghĩ nó sẽ nghe theo bất kỳ lý\n"
    .string "do nào với tình trạng hiện tại của nó.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "QUÝ: {PLAYER} làm ơn đi!\n"
	.string "Làm ơn thách đấu với tui đi mà.$"

MauvilleCity_Text_WallyHereICome:
	.string "QUÝ: Cảm ơn bạn, {PLAYER}.\p"
	.string "Rồi… Tui tới đây!$"

MauvilleCity_Text_WallyDefeat:
	.string "QUÝ: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "Tui thua rồi…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "QUÝ: CHÚ ơi…\n"
	.string "Con sẽ về lại GIẢN ĐƠN…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "Cảm ơn bạn, {PLAYER}.\n"
	.string "Làm NHL rất khó, phải không?\p"
	.string "Không phải chỉ bắt POKéMON và\n"
	.string "đi thách đấu là đủ. Đó không phải\l"
	.string "là những gì mà NHL thực sự làm.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "CHÚ: QUÝ, con không cần phải\n"
	.string "buồn lòng như vậy.\p"
	.string "Lý do nào, cái gì giúp cho con\n"
	.string "trở nên mạnh hơn và mạnh hơn?\p"
	.string "Thôi, về nhà nè.\n"
	.string "Mọi người đang chờ con.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "CHÚ: {PLAYER}, chú vừa mới nhận ra\n"
    .string "con chắc là NHL đã luôn giúp đỡ\l"
    .string "QUÝ khi nó bắt được\l"
    .string "POKÉMON cho mình.\p"
	.string "Sao con không ghé thăm tụi chú ở\n"
    .string "GIẢN ĐƠN một lần đi?\l"
    .string "Chú chắc chắn QUÝ sẽ rất thích.$"

MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Bíp!\p"
	.string "QUÝ: Chào {PLAYER}!\p"
	.string "Tui chỉ muốn nói là chú tui\n"
	.string "mới mua cho tui cái BẢN ĐỒ!\p"
	.string "Giờ tui có thể liên lạc với\n"
	.string "bạn lúc nào cũng được á, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "… … … … … Cạch!$"

MauvilleCity_Text_RegisteredWally:
	.string "Lưu số QUÝ\n"
	.string "vô BẢN ĐỒ.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SƠN: Hehe…\n"
	.string "Chú có coi trận đấu đó!\p"
	.string "Con là bạn với thằng bé QUÝ,\n"
	.string "phải không?\p"
	.string "Nhưng mà con không nhân nhượng\n"
	.string "mà hạ gục nó 1 cách ấn tượng.\p"
	.string "Yeah! Đó mới là một\n"
	.string "trận chiến POKéMON thực sự!\p"
	.string "Chú rất hâm mộ NHL như vậy!\p"
	.string "… … … … … …\n"
	.string "Chú sẽ cổ vũ cho con!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "QUÁCH: {PLAYER} ơi!\n"
	.string "Nhìn con có vẻ rất năng động!\l"
    .string "Đó là chuyện tốt, wahahahaha!\p"
    .string "Rồi! Quyết định rồi!\n"
	.string "Ta cần con giúp một chuyện, {PLAYER}!\p"
    .string "TP.HOA TÍM có một khu vực\n"
    .string "ở dưới đất gọi là NHÀ MÁY ĐIỆN.\p"
    .string "{PLAYER}, ta muốn con lại đó và\n"
	.string "tắt MÁY PHÁT ĐIỆN.\p"
    .string "MÁY PHÁT ĐIỆN hoạt động hơi bất thường.\n"
    .string "Hay nói cách khác là nguy hiểm.\p"
    .string "Đây, đây là CHÌA KHÓA để vô\n"
    .string "NHÀ MÁY ĐIỆN.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "QUÁCH: Con đừng có lo.\n"
	.string "Chuyện không có khó đâu.\p"
	.string "Để vô NHÀ MÁY ĐIỆN chỉ cần\n"
	.string "LƯỚT SÓNG qua ĐƯỜNG 110 thôi.\p"
	.string "Vậy thôi, trông cậy nhờ con nha!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "QUÁCH: Wahahahaha!\p"
	.string "Ta biết mà, {PLAYER}! Ta đã quyết\n"
	.string "định đúng khi nhờ vả con!\p"
	.string "Đây là quà của chú--TM chứa\n"
	.string "GIỰT ĐIỆN!\p"
	.string "Cầm đi, chú cho con mà!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "QUÁCH: Wahahahaha!\p"
	.string "Ta rất vui khi thấy người trẻ dám\n"
	.string "đứng lên và đảm nhận trách nhiệm!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Bạn cũng biết, có POKéMON\n"
	.string "để thách đấu này kia cũng đã…\p"
	.string "Mà nếu POKéMON bị thương,\n"
	.string "bạn phải chữa trị lại cho nó.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Con đường của thị trấn này trải dài\n"
    .string "về phía bắc và nam, phía đông và tây.\p"
    .string "Chính vì vậy nên mới có nhiều\n"
    .string "người qua lại.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Bạn có vô chỗ ÔNG QUANG XE ĐẠP chưa?\p"
	.string "Chủ tiệm, QUANG, là một người\n"
	.string "rất hào phóng.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Cho dù bạn có chạy XE ĐẠP đi nữa,\n"
	.string "POKéMON cũng sẽ nhảy ra mà thôi.$"

MauvilleCity_Text_CitySign:
	.string "TP.HOA TÍM\n"
	.string "“Thành phố tràn ngập màu sắc, niềm vui!”$"

MauvilleCity_Text_GymSign:
	.string "NHÀ THI ĐẤU TP.HOA TÍM\n"
	.string "CHỦ: QUANG\l"
	.string "“Một người tràn đầy năng lượng!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Hãy đạp xe trên đường và đánh thức\n"
    .string "tâm hồn của bạn!”\l"
	.string "QUANG XE ĐẠP$"

MauvilleCity_Text_GameCornerSign:
	.string "“Chơi được nhiều game!”\n"
	.string "HỘI GAME HOA TÍM$"

MauvilleCity_Text_ExplainTV:
	.string "Bạn có hay coi tivi không?\p"
	.string "Dạo này người ta mới thêm vô\n"
	.string "nhiều chương trình hay lắm.\p"
	.string "Coi tivi vui lắm. Hồi bữa tui\n"
	.string "còn thấy bạn tui trên tivi nữa.\p"
	.string "Với lâu lâu, người ta cho bạn\n"
	.string "lên tivi mà không báo luôn.\p"
	.string "Tui cũng muốn được lên tivi.\p"
	.string "Bởi vậy nên tui mới nói\n"
	.string "là bạn coi tivi thử đi.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Dạo này bạn có coi tivi không?$"
