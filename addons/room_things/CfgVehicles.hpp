class CfgVehicles
{
    class Land_ToiletBox_F; 
    class SCP_CB_Things_base: Land_ToiletBox_F
    {
        scope = 0;
        scopeCurator = 0;
        armor = 999999;
        armorStructural = 999;
        model = "\A3\Weapons_F\empty.p3d";
        destrType = "DestructNo";
        simulation = House;
        
        editorCategory = "SCP_Facility";
        mapSize = 20.27;
    };

//*******//
// Doors //
//*******//

    class SCP_CB_Things_Door1_Button : SCP_CB_Things_base
    {
        scope = 2;
        curatorScope = 2;
        displayName = CSTRING(Door1_Button); // Name in editor
        model = QPATHTOF(data\Door1.p3d); // Path to model
        editorSubCategory = "SCP_Doors";
        
        class UserActions
        {
            class Close_door_F
            {
                displayName = "Push Button";
                displayNameDefault = "<img image='z\RegalisSCP_CB\addons\textures\handsymbol.paa' size='2.5' />";
                position = "button_f";
                radius = 1;
                onlyForPlayer = 0;
                condition = "this animationSourcePhase ""open_door"" == 1";
                statement = "[this, ""Door1 Close"", ""open_door"", 2.5] execVM "QPATHTOF(functions\fnc_doorOperate.sqf)"; [this, ""Press"", 0.5, ""button_f""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };

            class Open_door_F: Close_door_F
            {
                displayName = "Push Button";
                condition = "this animationSourcePhase ""open_door"" == 0";
                statement = "[this, ""Door1 Open"", ""open_door"", 2.5] execVM "QPATHTOF(functions\fnc_doorOperate.sqf)"; [this, ""Press"", 0.5, ""button_f""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };
            
            class Close_door_B
            {
                displayName = "Push Button";
                displayNameDefault = "<img image='z\RegalisSCP_CB\addons\textures\handsymbol.paa' size='2.5' />";
                position = "button_b";
                radius = 1;
                onlyForPlayer = 0;
                condition = "this animationSourcePhase ""open_door"" == 1";
                statement = "[this, ""Door1 Close"", ""open_door"", 2.5] execVM "QPATHTOF(functions\fnc_doorOperate.sqf)"; [this, ""Press"", 0.5, ""button_b""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };
            
            class Open_door_B: Close_door_B
            {
                displayName ="Push Button";
                condition = "this animationSourcePhase ""open_door"" == 0";
                statement = "[this, ""Door1 Open"", ""open_door"", 2.5] execVM "QPATHTOF(functions\fnc_doorOperate.sqf)"; [this, ""Press"", 0.5, ""button_b""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };
        };
        
        class AnimationSources
        {
            class open_door
            {
                source = "user";
                animPeriod = 1.2;
                initPhase = 0;
            };
        };

        class Attributes 
        {
            class AuthorisationCheck {
                displayName = "Required Keycard Level";
                tooltip = "0 = No Keycard - 5 = Level 5/Omni Keycard";
                property = "AuthorisationCheckDoor1";
                control = "Edit";

                expression = "[_this, _value] remoteExec ['AuthLvl_fnc_InitAuthLvlVar'];";

                defaultValue = "0";

                //--- Optional properties
			    unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
				validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
				condition = "object"; // Condition for attribute to appear (see the table below)
				typeName = "NUMBER"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
            };
        };
    };

    class SCP_CB_Things_Door1_Button_Error : SCP_CB_Things_base
    {
        scope = 2;
        curatorScope = 2;
        displayName = CSTRING(Door1_Button_Error); // Name in editor
        model = QPATHTOF(data\Door1.p3d); // Path to model
        editorSubCategory   = "SCP_Doors";

        class UserActions
        {
            class Error_door_F
            {
                displayName = "Push Button";
                displayNameDefault = "<img image='z\RegalisSCP_CB\addons\textures\handsymbol.paa' size='2.5' />";
                position = "button_f";
                radius = 1;
                onlyForPlayer = 0;
                condition = "this animationSourcePhase ""open_door"" == 0";
                statement = "[this, ""Press (Denied)"", 0.5, ""button_f""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };

            class Error_door_B: Error_door_F
            {
                position = "button_b";
                statement = "[this, ""Press (Denied)"", 0.5, ""button_b""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };
        };
    };

    class SCP_CB_Things_Door1_Button_NoRespose : SCP_CB_Things_base
    {
        scope = 2;
        curatorScope = 2;
        displayName = CSTRING(Door1_Button_NoResponse); // Name in editor
        model = QPATHTOF(data\Door1.p3d); // Path to model
        editorSubCategory   = "SCP_Doors";

        class UserActions
        {
            class NoResponse_door_F
            {
                displayName = "Push Button";
                displayNameDefault = "<img image='z\RegalisSCP_CB\addons\textures\handsymbol.paa' size='2.5' />";
                position = "button_f";
                radius = 1;
                onlyForPlayer = 0;
                condition = "this animationSourcePhase ""open_door"" == 0";
                statement = "[this, ""Press"", 0.5, ""button_f""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };

            class NoResponse_door_B: NoResponse_door_F
            {
                position = "button_b";
                statement = "[this, ""Press"", 0.5, ""button_b""] execVM "QPATHTOF(functions\fnc_buttonSound.sqf)"";
            };
        };
    };
};