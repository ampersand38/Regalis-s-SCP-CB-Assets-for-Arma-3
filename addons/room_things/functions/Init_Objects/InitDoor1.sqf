_obj = _this select 0;

_door = _obj select 0;
_objString = name _door;

_authorityString = "authorisationLevel" + _objString;

_authLevel = missionNamespace getVariable [_authorityString, 0];

if (_authLevel == 0) then {
	
}