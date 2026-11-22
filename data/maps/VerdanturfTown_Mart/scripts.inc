VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Trong bất kỳ trận đấu POKéMON nào,\n"
    .string "+ST PHÉP rất là quan trọng.\p"
    .string "Nó giúp tăng sức mạnh của một số chiêu\n"
    .string "dù chỉ có hiệu lực trong một trận đấu.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Hình như người ta không bán mẹo\n"
	.string "hay chiến thuật dành cho HỘI THI ĐẤU…\p"
	.string "Chắc là vô đó, phải\n"
	.string "tự lực cánh sinh rồi…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "CẦU BẮT CHIM chỉ có tác dụng lên\n"
	.string "POKéMON yếu.\p"
	.string "GIẢN ĐƠN là nơi duy nhất\n"
	.string "để mua.$"
