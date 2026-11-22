RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hả? POKéMON tui dễ thương lắm hả?\n"
	.string "Thì tui biết mà.\p"
	.string "Nhưng nếu như bạn thích, tui sẽ\n"
	.string "sẵn lòng trao đổi nó với bạn.\p"
	.string "Tui sẽ đổi {STR_VAR_2} với\n"
	.string "{STR_VAR_1} nếu bạn muốn.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh…\n"
	.string "Xin hãy chăm POKéMON của tui thật kỹ.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hả? Đó nhìn đâu phải\n"
	.string "{STR_VAR_1} đâu.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Ủa nếu không muốn đổi thì thôi.\n"
	.string "POKéMON của tui cũng dễ thương mà…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "POKéMON nào cũng thấy cưng nếu\n"
	.string "bạn nuôi nó bằng tình yêu.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Ở chỗ nào cũng có\n"
	.string "POKéMON và con người.\p"
	.string "Bởi vậy tui mới thấy thích\n"
	.string "đi nhiều chỗ.$"
