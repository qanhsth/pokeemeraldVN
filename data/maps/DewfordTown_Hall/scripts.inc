DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Cái đang hot hả? Chắc chắn là\n"
	.string "“{STR_VAR_1}” rồi!\p"
	.string "Không thể tưởng tượng được\n"
	.string "cuộc sống thiếu đi “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Cái đang hot hả? Chắc chắn là\n"
	.string "“{STR_VAR_1}” rồi!\p"
	.string "Mà tui bắt đầu thấy chán rồi.\p"
	.string "Chắc phải kiếm cái khác thôi.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Tui đang dạy cho POKéMON về\n"
	.string "“{STR_VAR_1},”\l"
	.string "nhưng mà chưa được.\p"
	.string "Chắc là quá sức hay sao.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Tui đang tìm hiểu cái đang hot,\n"
	.string "“{STR_VAR_1}” nè.\p"
	.string "Có thiệt là có sự liên kết giữa\n"
	.string "giữa “{STR_VAR_1}”\l"
	.string "với “{STR_VAR_2}” không?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Trời!\n"
	.string "Vậy là linh cảm của mình đúng rồi!\p"
	.string "Tui đang bước thêm 1 bước tới\n"
	.string "cái đang hot hiện nay rồi!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Hả?!\n"
	.string "Vậy hả?!\p"
	.string "Chắc người già như tui\n"
	.string "khó nắm bắt trend ngày nay!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Toàn bộ về\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Hình như có chiếu lên TV nữa thì phải?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Bên kia bờ biển…\p"
	.string "“{STR_VAR_1}”\n"
	.string "còn nổi hơn bên đây nữa hả?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Tui sưu tầm\n"
	.string "“{STR_VAR_1}”\l"
	.string "của nhà phân phối bản quyền.\p"
	.string "Tui có con CÚP BẾ\n"
	.string "“{STR_VAR_1}” rồi…\p"
	.string "Đồ hiệu\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Với lại tranh hình\n"
	.string "“{STR_VAR_1}”\l"
	.string "nữa.\p"
	.string "Heheh, của tui không đó!\n"
	.string "Không có cho bạn được đâu!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "NHẬN BIẾT\n"
	.string "“{STR_VAR_1}” TỐT &\l"
	.string "“{STR_VAR_1}” XẤU…\p"
	.string "LIÊN KẾT GIỮA\n"
	.string "“{STR_VAR_1}” VÀ\l"
	.string "POKéMON…\p"
	.string "CÔNG DỤNG CỦA\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Ở đây chỉ có sách về\n"
	.string "“{STR_VAR_1}.” thôi.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "Ở đây có đề tựa,\n"
	.string "“TIẾNG HÉT CỦA {STR_VAR_1}” .$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "Ở đây có đề tựa,\n"
	.string "“NỤ CƯỜI CỦA {STR_VAR_1}”.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Tựa đề là “{STR_VAR_1}\n"
	.string "CUỐI CÙNG”.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Tựa đề là “{STR_VAR_1}\n"
	.string "ĐẦU TIÊN”.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Tui thấy “{STR_VAR_1}” rồi!\n"
	.string "Hay ha?\p"
	.string "Cứ như là cái ngầu nhất vậy đó!\p"
	.string "Thích ghê!\n"
	.string "Y như đồ thiệt vậy đó, hehe!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Không, không, không phải.\p"
	.string "Cái mà kêu là\n"
	.string "“{STR_VAR_1}”\l"
	.string "mà bạn thấy--không phải nó đâu.\p"
	.string "Cái thật nó…\n"
	.string "Nói sao ta?\l"
	.string "Sắt hơn, mềm hơn!\p"
	.string "Mà thôi. Vậy cũng được rồi!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Nói nghe nè, tui mới sáng tác\n"
	.string "bài hát về “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "đang rất là nổi.\p"
	.string "OK, nghe thử nè!\n"
	.string "… …\p"
	.string "Ủa!\n"
	.string "{STR_VAR_1}!\p"
	.string "Tuyệt vời quá,\n"
	.string "{STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… …\p"
	.string "Tui nói thiệt với ông,\n"
	.string "luyện hát trước đi\l"
	.string "rồi hả tìm hiểu\l"
	.string "“{STR_VAR_1}.”$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "À mà nãy tui có nói, tụi\n"
	.string "mình nên tập hợp lại tổ chức\l"
	.string "tiệc “{STR_VAR_1}”\l"
	.string "trên đảo đi.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Ồ, ý kiến hay đó!\p"
	.string "Làm 1 lần thử coi\n"
	.string "ai giỏi\l"
	.string "“{STR_VAR_1}.” nhất\l"
	.string "Cực kỳ đồng ý!\p"
	.string "Kể từ ngày hôm nay, cuộc sống ta\n"
	.string "sẽ xoay quanh “{STR_VAR_1}”!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Tui đang nghĩ là…\p"
	.string "Bạn có nghĩ là\n"
	.string "“{STR_VAR_1}” đã từ thứ gì đó\l"
	.string "hợp thời cho tới khi trở thành\l"
	.string "1 phần trong đời sống không?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Hả, gì?\n"
	.string "Cái gì nhiều?\p"
	.string "Mà cũng đúng là\n"
	.string "“{STR_VAR_1}”\l"
	.string "vẫn còn nằm trong đầu, dù cho\l"
	.string "có đang ngủ hay là thức.\p"
	.string "Tất nhiên, bạn là TIẾN SĨ\n"
	.string "“{STR_VAR_1}”\l"
	.string "rồi!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Nếu tui với bạn hợp tác với nhau,\n"
	.string "tụi mình sẽ bất khả chiến bại về\l"
	.string "“{STR_VAR_1}”!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Đúng rồi, bạn ơi!\p"
	.string "Tụi mình nên làm 1 CẶP\n"
	.string "“{STR_VAR_1}” đi!\p"
	.string "Không phải sẽ rất thú vị sao?\n"
	.string "Hahahah!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Đối với tui, BOM SÌNH đang\n"
	.string "nổi nhất. Đúng rồi đó.\p"
	.string "Hở? Bạn nói là bạn không có\n"
	.string "biết cái gì về BOM SÌNH luôn?\p"
	.string "Tội nghiệp quá.\n"
	.string "Cho bạn 1 cái nè.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Tui yêu BOM SÌNH.\p"
	.string "Mà POKéMON có chiêu\n"
	.string "“{STR_VAR_1}”\l"
	.string "thì tui cũng thích nữa.$"

