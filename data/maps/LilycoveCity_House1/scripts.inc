LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.string "POKéMON là cộng sự với con người.\n"
	.string "Tụi nó không phải công cụ.\p"
	.string "Không may là có người tới giờ\n"
	.string "vẫn chưa nhận ra chuyện đó…$"

LilycoveCity_House1_Text_Kecleon:
	.string "KECLEON: Rừ rô rố?$"

