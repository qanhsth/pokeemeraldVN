SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Chào con! Ta là ÔNG ĐẶT TÊN!\n"
	.string "Ta là thầy bói biệt danh!\p"
	.string "Con có muốn ta nhận xét\n"
	.string "biệt danh của POKéMON không?$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Ta nên nhận xét biệt danh của\n"
	.string "POKéMON nào?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, phải không? Tên đó\n"
	.string "nghe cũng hay.\p"
	.string "Nhưng! Nếu ta nói, ta có thể\n"
	.string "gợi ý cho con cái tên hay hơn thì sao?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Rồi, vậy thì biệt danh\n"
	.string "mới cho nó là gì?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Xong! Kể từ giờ, POKéMON này\n"
	.string "sẽ được gọi là {STR_VAR_1}!\p"
	.string "Hay hơn tên trước rồi!\n"
	.string "Phải nói là con rất may mắn đó!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "À vậy ha.\n"
	.string "Nhớ ghé lại nha.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Xong! Kể từ giờ, POKéMON này\n"
	.string "sẽ được gọi là {STR_VAR_1}!\p"
	.string "Nghe thì có vẻ không khác lắm,\n"
	.string "nhưng mà tên này nghe ổn hơn nhiều!\p"
	.string "Thôi vậy cũng được rồi!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1}!\p"
	.string "Nghe mỹ miều quá!\n"
	.string "Không thể chê được!\p"
	.string "Con nên trân trọng\n"
	.string "{STR_VAR_1} từ giờ và về sau.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Thôi con.\n"
	.string "Cái đó là TRỨNG mà!$"

