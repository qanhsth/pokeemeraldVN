LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "PHƯƠNG: {PLAYER}! Lâu rồi không gặp!\p"
	.string "Ủa? Trong lúc tui đi suối nước nóng, thì\n"
	.string "ông đã lấy HUY HIỆU NHIỆT luôn rồi.\p"
	.string "Chắc ông bắt được\n"
	.string "POKéMON mạnh lắm ha…\l"
	.string "Không, chắc là do ông nuôi kỹ thôi.\p"
	.string "Chắc tui nghĩ ông sẽ cần\n"
	.string "cái này.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "PHƯƠNG: Có KIẾNG BẢO HỘ, ông sẽ\n"
	.string "có thể đi qua sa mạc ở ĐƯỜNG 111\l"
	.string "mà hong bị bụi bay vô mắt.\p"
	.string "Nhưng mà trời ơi, {PLAYER} ơi…\n"
	.string "Thách đấu GYM…\p"
	.string "Tui cá là ông đang cố gắng hết sức\n"
	.string "để hong phải thua tui rồi!\p"
	.string "{PLAYER} ơi, tui sẽ đi thách đấu\n"
	.string "ba ông ở NHÀ THI ĐẤU HOA CAM.\p"
	.string "Hẹn gặp lại!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "DŨNG: Ê, {PLAYER}, cũng lâu rồi ha.\n"
	.string "Nay sao rồi?\p"
	.string "Hmm…\n"
	.string "Cũng được nhiều HUY HIỆU rồi đó.\p"
	.string "Được rồi.\n"
	.string "Cho bà nè.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "DŨNG: Nhớ đeo cái này lên\n"
	.string "nếu bà tính đi vô sa mạc ở\l"
	.string "ĐƯỜNG 111.\p"
	.string "Chắc phải có một số loài POKéMON\n"
    .string "chỉ sống ở sa mạc.\l"
    .string "Bà cũng nên đi kiếm thử đi.\p"
    .string "Còn tui thì…\n"
	.string "Tui đang cân nhắc thách đấu THƯỜNG,\l"
    .string "CHỦ GYM HOA CAM.\p"
    .string "Không giống như bà đâu, {PLAYER},\n"
    .string "ba của bà nhìn rất là cứng rắn.\p"
    .string "Hẹn gặp lại!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Ta có cái TRỨNG này.\p"
	.string "Ta tính ấp nó bằng cách chôn trong cát\n"
	.string "ở suối nước nóng.\l"
	.string "Nhưng mà chỉ vậy là chưa đủ…\p"
	.string "Ta nghe nói là nếu được\n"
	.string "NHL để chung với POKéMON và\l"
	.string "đem theo thì sẽ tốt hơn.\p"
	.string "Con là NHL, phải không?\n"
	.string "Và POKéMON của con tràn đầy sức sống.\p"
	.string "Vậy, con nghĩ sao?\n"
	.string "Con sẽ đem theo và ấp cái TRỨNG này chứ?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Tốt! Ta hy vọng con sẽ đi bộ\n"
	.string "thiệt nhiều, đem theo cái TRỨNG này!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} nhận TRỨNG.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Ủa? Con để nhiều POKéMON quá rồi.\n"
	.string "Không còn chỗ để TRỨNG nữa…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Nếu con thực lòng…\p"
	.string "Nếu con thực tâm muốn biết\n"
	.string "cách ấp TRỨNG, ta sẽ chỉ cho.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Lâu lâu, người ta sẽ tìm thấy\n"
	.string "1 cái TRỨNG ở chỗ CHĂM POKéMON.\p"
	.string "Mà chắc là người ta chỉ đồn vậy thôi.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "Tụi ta lấy quá trời nước nóng,\n"
    .string "mà suối nước nóng không bao giờ cạn.\p"
    .string "Thật kỳ diệu phải không?\p"
    .string "Suối nước nóng này xuất hiện gần\n"
    .string "núi lửa đang hoạt động. Mạch nước dưới\l"
    .string "lòng đất được mắc ma làm nóng để trào\l"
    .string "lên thành suối nước nóng.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Cảm giác chôn mình trong cát nóng…\n"
	.string "Phùuu…\p"
	.string "Ấm áp và tuyệt trần…\p"
	.string "Hể? Gàooo! Ây da!\p"
	.string "Có POKéMON cắn vô đít ta!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Ụa, con có thích suối nước nóng không?\p"
	.string "Nếu mà có thì tuyệt vời quá,\n"
	.string "còn trẻ vậy mà.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Ngày nào em cũng tắm suối nước nóng.\p"
	.string "Em muốn trở nên xinh đẹp và mạnh mẽ\n"
	.string "giống chị CHỦ GYM, HOẢ LY, vậy á.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Nếu để POKéMON trong suối nước nóng,\n"
	.string "thì bồn tắm sẽ trở nên rất lạ kỳ.\p"
	.string "Nó có thể là bồn tắm điện, bồn tắm\n"
	.string "bong bóng, hay thậm chí là dung nham…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Khoa học chứng minh suối nước nóng có\n"
    .string "công dụng làm giảm căng thẳng đầu óc,\l"
    .string "giảm đau nhức cơ bắp, giải quyết\l"
    .string "các vấn đề tình cảm, và thu hút\l"
    .string "tiền bạc…$"

LavaridgeTown_Text_TownSign:
	.string "THỊ TRẤN NÚI LỬA\p"
	.string "“SUỐI NƯỚC NÓNG TRUNG TÂM POKéMON\n"
	.string "Một nơi lý tưởng để thư giãn!”$"

LavaridgeTown_Text_GymSign:
	.string "NHÀ THI ĐẤU THỊ TRẤN NÚI LỬA\n"
	.string "CHỦ: HOẢ LY\l"
	.string "“Một người có niềm đam mê cháy bỏng!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "CỬA HÀNG DƯỢC LIỆU POKéMON\n"
	.string "“Thuốc đắng--dã tật!”$"

