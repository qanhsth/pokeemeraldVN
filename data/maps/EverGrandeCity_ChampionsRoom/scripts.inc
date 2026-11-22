EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "HẢI LY: Chào mừng, {PLAYER}.\p"
	.string "Cái vụ ở TP.LƯU NIẾT đó…\n"
	.string "Đó là một cái công lớn, khi chính bạn\l"
    .string "tự mình chấm dứt cuộc khủng hoảng đó.\p"
    .string "Ụa!\p"
    .string "Sẽ không công bằng nếu nói chỉ có một\n"
    .string "mình bạn chấm dứt cuộc khủng hoảng.\p"
	.string "Bạn đã vượt qua tình huống khó khăn đó\n"
    .string "bằng cách phối hợp với POKéMON của mình.\p"
    .string "Chúng ta, những NHL, nuôi dưỡng POKéMON\n"
    .string "bằng các loại vật phẩm và dạy cho tụi nó\l"
    .string "biết cách chiến đấu.\p"
	.string "Nhưng mà chính chúng ta cũng học được\n"
    .string "rất nhiều điều từ POKéMON.\p"
    .string "Và đây chính là nơi những gì bạn đạt\n"
    .string "được, sẽ được thử thách với những gì\l"
    .string "mà người khác cũng đạt được như bạn.\p"
    .string "Ngay lúc này!\p"
	.string "Ai có thể khiêu vũ một cách duyên dáng\n"
    .string "nhất cùng POKéMON của mình tại HOENN?\p"
    .string "Hãy thể hiện cho tui thấy đi!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Một NHÀ VÔ ĐỊCH như tui, lại bị hạ…\p"
	.string "Đó là một công sức vô cùng lớn.\n"
	.string "Bạn là một con người lịch sự.\l"
	.string "Làm cho người ta phải trầm trồ!\p"
	.string "Chúc mừng bạn, {PLAYER}!\p"
	.string "Bạn chính là một NHL POKéMON\n"
	.string "cao quý hơn ai khác!$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "HẢI LY: POKéMON mà bạn gởi\n"
	.string "ra ván đấu…\p"
	.string "Lúc thì nhảy múa như một cơn gió\n"
    .string "mùa xuân, lúc thì tấn công\l"
    .string "như một tia chớp.\p"
    .string "Chính sự nhẹ nhàng mà vững chãi, trang\n"
    .string "nhã, bạn đã dẫn dắt POKéMON của mình.\p"
	.string "Kể cả tui cũng thấy choáng ngợp trước\n"
    .string "màn trình diễn điêu luyện của bạn!\p"
    .string "Giờ đây, bạn đang đứng trên đỉnh\n"
    .string "vinh quang của LIÊN ĐOÀN POKéMON.\p"
    .string "Tui xin tuyên bố, bạn là nhà vô địch\n"
    .string "mới của vùng HOENN…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "PHƯƠNG: {PLAYER} ơi!\p"
	.string "Tui có chút lời khuyên cho ông\n"
	.string "trước khi đấu với NHÀ VÔ ĐỊCH…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "PHƯƠNG: Hở?\n"
	.string "Ủa, là sao, là sao dạ?\p"
	.string "{PLAYER}…\n"
	.string "Không lẽ…\l"
	.string "Đã kết thúc rồi sao?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "DŨNG: {PLAYER}!\p"
	.string "Bà có muốn nghe chút lời khuyên\n"
	.string "trước khi đấu với NHÀ VÔ ĐỊCH không?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "DŨNG: {PLAYER}…\p"
	.string "Bà nói với tui là…\n"
	.string "Bà đã hạ NHÀ VÔ ĐỊCH rồi sao?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "TS.BÌNH: Thấy chưa?\n"
	.string "Ba đã nói sao, {RIVAL}?\p"
	.string "Không phải ba đã nói là đừng có\n"
	.string "lo về {PLAYER} sao?\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER} ơi, con đã làm được rồi.\p"
	.string "Lúc mà chú nghe nói con đã hạ được\n"
	.string "cha mình ở NHÀ THI ĐẤU HOA CAM,\l"
	.string "chú còn nghĩ có lẽ con sẽ có thể…\p"
	.string "Nhưng mà giờ, con đã là\n"
	.string "NHÀ VÔ ĐỊCH rồi!\p"
	.string "À, phải rồi!\p"
	.string "DS.POKéMON của con sao rồi?\n"
	.string "Để chú coi thử coi.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "TS.BÌNH: Dù sao thì,\n"
	.string "chúc mừng con nha!\p"
	.string "Hãy tự tin mà bước vô căn phòng cuối!$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "HẢI LY: {PLAYER} ơi…\p"
	.string "À không, để tui nói lại.\p"
	.string "NHÀ VÔ ĐỊCH mới!\p"
	.string "Xin hãy đi với tui.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "HẢI LY: Tui xin lỗi, nhưng mà…\p"
	.string "Kể từ chỗ này, chỉ những NHL\n"
	.string "đã là NHÀ VÔ ĐỊCH mới được vô.\p"
	.string "Bạn phải ra ngoài chờ với\n"
	.string "TS.BÌNH.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "PHƯƠNG: Trờiiợii…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Giỡn thôi! Không sao!\n"
	.string "Thôi cũng xong rồi!\p"
	.string "{PLAYER}{KUN}!\n"
	.string "Thực lòng, chúc mừng ông!$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "DŨNG: Haaảaaá?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Vậy là chuyện đã xong rồi.\p"
	.string "{PLAYER}, hay lắm!\n"
	.string "Chúc mừng nha!$"

