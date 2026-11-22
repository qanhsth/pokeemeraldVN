PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Coi thử con {STR_VAR_2} này đi!\p"
	.string "Là con {STR_VAR_2} tui mới bắt\n"
	.string "được hồi qua, đặng mừng sinh nhật!\p"
	.string "Àaa, bạn thích nó phải không!?\n"
	.string "Sau cùng thì, cũng vô giá mà!\p"
	.string "Tui nói bạn nghe. Tui sẵn lòng\n"
	.string "đổi nó đặng lấy con {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "À, con này là {STR_VAR_1} hả?\p"
	.string "Cũng giống giống {STR_VAR_2},\n"
	.string "mà cũng không khác cho lắm.\p"
	.string "Cám mơn nha!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Thôi, thôi, thôi! Tui không có nhận\n"
	.string "con nào khác với {STR_VAR_1} đâu!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "À, vậy là bạn không muốn\n"
	.string "đổi hả?\p"
	.string "Vậy thôi. Tui cũng có muốn\n"
	.string "đổi hay gì đâu.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Tui biết là mình có thể\n"
	.string "tự đi kiếm, nhưng mà…\p"
	.string "Tui thực lòng muốn có BAGON\n"
	.string "mà người khác bắt được…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "Cái đó là DS.POKéMON hả?\p"
	.string "Vậy là bạn gặp được nhiều\n"
	.string "loại POKéMON lắm hả?\p"
	.string "Ước gì được như bạn.$"

