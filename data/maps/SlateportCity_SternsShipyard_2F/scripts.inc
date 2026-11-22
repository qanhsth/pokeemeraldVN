SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
    .string "Thiết kế một con tàu lớn giống như\n"
    .string "xây dựng một tòa nhà lớn, hơn là\l"
    .string "lắp ráp một phương tiện vận tải.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
    .string "Bạn có thấy lạ không khi một con\n"
    .string "tàu nặng làm bằng sắt lại nổi được?\p"
    .string "Nó nổi được nhờ một nguyên lý\n"
    .string "gọi là lực nổi.$"

