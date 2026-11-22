FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Gừroaaaa! Tui rất cần!\n"
	.string "Bạn phải cho tui cái {STR_VAR_1}!\l"
	.string "Tui sẽ làm mọi thứ để có được nó!\p"
	.string "…Ụa… Bạn có nghe tui nói hong dạ?\n"
	.string "Tiếng hét từ tận đáy lòng tui?\p"
	.string "Nếu mà có, thì liệu bạn sẽ đổi\n"
	.string "{STR_VAR_1} lấy {STR_VAR_2} của tui,\l"
	.string "nhaaa?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Ừưư, phải vậy chứ!\p"
	.string "{STR_VAR_1}, chào em!\n"
	.string "{STR_VAR_2}, gởi cho bạn nha!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Ủa mà, đâu phải đâu.\n"
	.string "Cái đó đâu phải {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Không hả? Bạn không chịu hả?\n"
	.string "Kể cả sau khi tui đã mở lòng với bạn?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Tui sẽ làm cho VOLBEAT mạnh\n"
	.string "hơn kể từ thời điểm này!\p"
	.string "Mong là bạn cũng làm vậy với PLUSLE!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Đổi POKéMON với người khác…\p"
	.string "Cũng giống như là đổi kỷ niệm\n"
	.string "của mình với người khác vậy.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Gừ mô mố?$"

