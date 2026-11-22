PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "E-hèm!\p"
	.string "Tui là người quan trọng nhất CLB\n"
	.string "HÂM MỘ POKéMON, em trai của\l"
	.string "CHỦ TỊCH.\p"
	.string "Tui tới đây đi du lịch với\n"
	.string "POKéMON, ừm, đúng rồi đó.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Aaa!\n"
	.string "POKéMON của bạn…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Rõ ràng là nó mến bạn rất nhiều.\p"
	.string "POKéMON mà dễ mến và đáng yêu\n"
	.string "thì nên nhận cái TM này chứ hả?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hừmm…\n"
	.string "Không tệ, mà cũng không tốt.\p"
	.string "Với tư cách NHL, bạn, cần phải\n"
	.string "nỗ lực hơn nữa.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Nhìn nó hung dữ quá.\p"
	.string "POKéMON đáng sợ như vầy\n"
	.string "xứng đáng nhận cái TM này.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Nếu POKéMON yêu quý bạn, sức mạnh\n"
	.string "của TRẢ LẠI sẽ được gia tăng.\p"
	.string "Còn nếu nó không ưa bạn, sức mạnh\n"
	.string "của ẤM ỨC sẽ được gia tăng.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "À, đúng rồi. Cỡ {STR_VAR_1} hoặc mấy bữa\n"
	.string "sau, tui sẽ có 1 hoặc 2 cái tốt.\p"
	.string "Lúc đó bạn quay lại đây.\n"
	.string "Tui sẽ cho bạn 1 cái TM,\l"
	.string "phù hợp với POKéMON của bạn.$"

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILL: Rừ rii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Hình như nó rất thân thiện\n"
	.string "với CHỦ.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL: Rừ rư ri!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Hình như nó không khoái\n"
	.string "CHỦ cho lắm.$"

