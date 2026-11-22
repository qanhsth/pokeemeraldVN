FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	pokemartlistend

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "Tui đang loay hoay không biết là nên\n"
	.string "cho SKITTY của tui tiến hoá hay không.\p"
	.string "Chỉ cần xài NGUYỆT ĐÁ thôi, mà sao\n"
	.string "khó quyết quá…\p"
	.string "Nếu mà tiến hoá, nó sẽ\n"
	.string "mạnh hơn rất nhiều.\p"
	.string "Nhưng mà ngoại hình cũng sẽ thay đổi.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY: Méo?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "CỤC VÀNG này tui kiếm được…\n"
	.string "Tui tính đem bán, để coi\l"
	.string "tại sao không có ai xài.$"

