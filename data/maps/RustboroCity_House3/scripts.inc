RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Tại vì là POKéMON của mình nên tui phải\n"
	.string "đặt cái biệt danh cho nó đẹp mới được!\p"
	.string "Đó là cách mà tui thể hiện…\n"
	.string "sự độc đáo, đúng rồi đó!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Mà đặt tên PIKACHU là\n"
	.string "PEKACHU? Nghe trớt quớt quá vậy.\p"
	.string "Tui cũng biết là nên đặt\n"
	.string "tên cho dễ nhớ, mà sao thấy cứ kỳ kỳ…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

