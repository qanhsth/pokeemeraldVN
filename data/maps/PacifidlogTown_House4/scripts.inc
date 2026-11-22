PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Người ta cứ nói là thấy con POKéMON\n"
	.string "bay vòng vòng HOENN.\p"
	.string "Là lúc nào nó cũng bay vậy ha sao?\n"
	.string "Nó không nghỉ mệt ở đâu đó hả?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Một con POKéMON trên trời!\n"
	.string "POKéMON trên trời!!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Bạn từ đâu tới vậy?$"

PacifidlogTown_House4_Text_YesTown:
	.string "OK hả?\n"
	.string "THỊ TRẤN OK hả?\p"
	.string "Đó giờ chưa nghe chỗ nào giống vậy.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Không hả? Không hợp lý xíu nào.\n"
	.string "Bạn phải từ đâu tới chứ.\p"
	.string "Ủa! Khoan! Không lẽ bạn tính nói là\n"
	.string "bạn được sanh ra từ dưới đáy biển?$"

