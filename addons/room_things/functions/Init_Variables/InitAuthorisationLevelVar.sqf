_obj = _this select 0;
_authorityValue = _this select 1;

_objstring = name _obj;
_authorityString = "authorisationLevel" + _objstring;

missionnamespace setVariable [_authorityString, _authorityValue];