FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	pokemartlistend

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "XUA ĐUỔI+ hiệu lực rất lâu,\n"
	.string "và nó rất hiệu quả.\p"
	.string "Nó còn tốt hơn nhiều so với\n"
	.string "XUA ĐUỔI thường.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Tui lúc nào cũng trữ nhiều đồ\n"
	.string "hơn là mình cần.\p"
	.string "Bạn không bao giờ biết trước được chuyện\n"
	.string "gì sẽ xảy ra. An toàn là trên hết!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "KẸO HIẾM làm cho POKéMON\n"
	.string "tăng lên 1 cấp ngay lập tức.$"

