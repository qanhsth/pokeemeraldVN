SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "E hèm! Ta là CHỦ TỊCH\n"
	.string "CLB HÂM MỘ POKéMON!\p"
	.string "Là CHỦ TỊCH, đương nhiên ta\n"
	.string "là quan trọng nhất!\p"
    .string "Không ai có thể qua được ta khi nói về\n"
	.string "nuôi POKéMON. Không ai hết á!\p"
    .string "À, để ta kể cho con nghe về\n"
    .string "CUỘC THI POKéMON.\p"
    .string "Đó là sự kiện mà người ta có thể khoe\n"
    .string "POKéMON cho cả thế giới chiêm ngưỡng!\p"
	.string "Tuy nhiên, sự kiện chỉ được tổ chức ở\n"
    .string "nơi xa, nên không tham gia thường được.\p"
    .string "Đó là lý do mà tụi mình tụ tập ở\n"
    .string "đây để khoe POKéMON cho người khác và\l"
    .string "cùng chiêm ngưỡng POKéMON của họ.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "POKéMON của NHL đã tham gia\n"
	.string "CUỘC THI POKéMON…\l"
	.string "Tui muốn được thấy POKéMON đó.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Er-hem! Ta thấy là con đã tham gia\n"
	.string "CUỘC THI POKéMON rồi!\p"
    .string "Xin hãy! Hãy cho ta coi cách con\n"
    .string "đã nuôi dưỡng POKÉMON của mình.\p"
    .string "Ta rất vui mừng khi thấy POKÉMON\n"
	.string "được các NHL khác nuôi dưỡng.\p"
    .string "Nét mặt hạnh phúc của POKéMON được\n"
    .string "nuôi dưỡng với sự chăm sóc chu đáo…\p"
    .string "Ánh mắt nhân hậu của NHL đã\n"
    .string "nuôi nấng và chăm sóc POKéMON…\p"
	.string "Chỉ cần nghĩ đến điều đó thôi cũng \n"
    .string "khiến trái tim ta tràn ngập niềm vui.\p"
    .string "Trời ơi! Ta xin lỗi!\n"
    .string "Ta nói hơi nhiều rồi, thông cảm nha!\p"
    .string "Xin hãy! Hãy cho ta coi\n"
    .string "POKéMON của con sao rồi!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "POKéMON sao rồi?\n"
	.string "Cho ta coi thử coi.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hm, hm…\n"
	.string "Hiểu rồi…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmmm… Không tệ, mà cũng\n"
	.string "không tốt…\p"
	.string "Là một NHL, con phải nỗ lực hơn\n"
	.string "nữa cho POKéMON này!\p"
	.string "Tạm thời thì ta nghĩ con nên\n"
	.string "cho nó thêm mấy cái {POKEBLOCK} nha?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Trời…\p"
	.string "POKéMON của con đang mạnh khoẻ,\n"
	.string "nên là con xứng đáng nhận thưởng.\p"
	.string "Tiếc là con không còn chỗ để\n"
	.string "cái này vô TÚI.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "{STR_VAR_1} của con, đang lớn lên\n"
    .string "một cách thật ấn tượng!\l"
    .string "Đúng là một chủng loài đẹp đẽ!\p"
    .string "Nhưng! Nếu con cho nó cái này,\n"
    .string "nó sẽ còn lớn tốt hơn nữa! Đúng vậy!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
    .string "Cho POKÉMON đeo KHĂN ĐỎ.\p"
    .string "Người ta sẽ nhận ra sự ngầu lòi\n"
    .string "của POKÉMON đó!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Cho POKéMON đeo KHĂN XANH.\p"
    .string "Vẻ đẹp của nó sẽ được tôn lên\n"
    .string "rất nhiều!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
    .string "Cho POKéMON đeo KHĂN HỒNG.\p"
	.string "Nó sẽ làm nổi bật sự dễ thương của\n"
    .string "POKéMON đó hơn nữa!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
    .string "Cho POKéMON đeo KHĂN XANH LÁ.\p"
    .string "Nó sẽ làm nổi lên\n"
	.string "sự thông minh của POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
    .string "Cho POKéMON đeo KHĂN VÀNG.\p"
    .string "Nó sẽ tăng cường sức mạnh\n"
    .string "của POKéMON lên rất nhiều!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
    .string "Xin lỗi, ta không còn gì khác\n"
    .string "để tặng con nữa! Không còn gì nữa!\p"
    .string "Dù sao thì, con đã được hưởng phước\n"
    .string "nuôi POKéMON mà không cần phải xài\l"
	.string "bất kỳ vật phẩm nào!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
    .string "Tui rất thích nhìn mấy con POKéMON\n"
    .string "yêu quý người nuôi.\p"
    .string "POKéMON rất nhạy cảm với\n"
    .string "cảm xúc của NHL.\p"
	.string "Đối xử với POKéMON bằng tình yêu\n"
    .string "và sự quan tâm, tụi nó sẽ yêu quý bạn.\p"
    .string "Khi POKéMON yêu quý bạn,\n"
    .string "hãy đem tới cho tui coi nha.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
    .string "POKéMON thực sự rất yêu quý bạn.\p"
    .string "Dành cho bạn, một NHL đầy lòng\n"
    .string "trắc ẩn, một món quà từ CLB HÂM MỘ!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
    .string "POKéMON rất nhạy cảm với\n"
    .string "cảm xúc của NHL.\p"
	.string "Đối xử với POKéMON bằng tình yêu\n"
    .string "và sự quan tâm, tụi nó sẽ yêu quý bạn.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
    .string "Nếu bạn cứ để POKéMON ngất xỉu\n"
    .string "trong trận đấu, nó sẽ giận bạn.\p"
	.string "Rồi sau này, nó sẽ không còn\n"
    .string "tin tưởng vào bạn nữa.\p"
    .string "Nói cách khác, nó sẽ\n"
    .string "không còn thích bạn đâu.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
    .string "POKéMON có thích xài vật phẩm\n"
    .string "trên người nó không ta?\p"
    .string "Con của tui tỏ ra rất vui\n"
    .string "khi được cho một miếng ĐẠM.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY: Mmmeooéoo…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON: Khưưưư…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL: Ma ri mà rí?$"

