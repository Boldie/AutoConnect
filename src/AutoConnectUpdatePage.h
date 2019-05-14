/**
 * Define dialogs to operate sketch binary updates operated by the
 * AutoConnectUpdate class.
 * @file   AutoConnectUpdatePage.h
 * @author hieromon@gmail.com
 * @version    0.9.9
 * @date   2019-05-14
 * @copyright  MIT license.
 */

#ifndef _AUTOCONNECTUPDATEPAGE_H
#define _AUTOCONNECTUPDATEPAGE_H

// Define the AUTOCONNECT_URI_UPDATE page to select the sketch binary
// for update and order update execution.
const AutoConnectUpdate::ACElementProp_t AutoConnectUpdate::_elmCatalog[] PROGMEM = {
  { AC_Text, "caption", nullptr, nullptr },
  { AC_Radio, "firmwares", nullptr, nullptr },
  { AC_Submit, "update", "UPDATE", AUTOCONNECT_URI_UPDATE_ACT }
};
const AutoConnectUpdate::ACPage_t AutoConnectUpdate::_auxCatalog PROGMEM = {
  AUTOCONNECT_URI_UPDATE, "Update", false, AutoConnectUpdate::_elmCatalog
};

// Define the AUTOCONNECT_URI_UPDATE_ACT page to display during the
// update process.
const AutoConnectUpdate::ACElementProp_t AutoConnectUpdate::_elmProgress[] PROGMEM = {
  { AC_Element, "loader", "<style>.loader{border:2px solid #f3f3f3;border-radius:50%;border-top:2px solid #555;width: 12px;height:12px;-webkit-animation:spin 1s linear infinite;animation:spin 1s linear infinite}@-webkit-keyframes spin{0%{-webkit-transform:rotate(0deg)}100%{-webkit-transform:rotate(360deg)}}@keyframes spin{0%{transform:rotate(0deg)}100%{transform:rotate(360deg)}}</style>", nullptr },
  { AC_Element, "c1", "<div style=\"display:inline-block\">", nullptr },
  { AC_Element, "binname", nullptr, nullptr },
  { AC_Element, "c2", "&ensp;from&ensp;", nullptr },
  { AC_Element, "url", "</dv>", nullptr },
  { AC_Element, "c3", "<div id=\"progress\">Updating...<span style=\"display:inline-block;vertical-align:middle;margin-left:7px\">", nullptr },
  { AC_Element, "progress_meter", "<meter min=\"0\" />", nullptr },
  { AC_Element, "progress_loader", "<div class=\"loader\" />", nullptr },
  { AC_Element, "c4", "</span></div></div>", nullptr },
  { AC_Text, "status", nullptr, nullptr },
  { AC_Element, "c5", "<script type=\"text/javascript\">var ws;window.onload=function(){ws=new WebSocket('", nullptr },
  { AC_Element, "wsurl", nullptr, nullptr },
  { AC_Element, "c6", "');ws.onopen=function(){ws.onmessage=function(e){var pl=e.data.split(',');if(pl[0]=='#e'){location.href='/_ac/update_result';}else if(pl[0]=='#p'){incr(pl[1]);}};};ws.onclose=function(e){console.log('WS close('+e.code+')'+e.reason);if(e.code!=1000){document.getElementById('status').textContent='WebSocket connection closed. ('+e.code+')';}};ws.onerror=function(e){if(ws.readyState==1){document.getElementById('status').textContent='WebSocket '+e.type;}};};window.onbeforeunload=function(){ws.close();};", nullptr },
  { AC_Element, "inprogress_meter", "function incr(pv){var iv=pv.split(':');var pb=document.getElementById('progress').getElementsByTagName('meter');pb[0].setAttribute('value',iv[0]);pb[0].setAttribute('max',iv[1]);}", nullptr },
  { AC_Element, "inprogress_loader", "function incr(pv){}", nullptr },
  { AC_Element, "c7", "</script>", nullptr },
};
const AutoConnectUpdate::ACPage_t AutoConnectUpdate::_auxProgress PROGMEM = {
  AUTOCONNECT_URI_UPDATE_ACT, "Update", false, AutoConnectUpdate::_elmProgress
};

// Definition of the AUTOCONNECT_URI_UPDATE_RESULT page to notify update results
const AutoConnectUpdate::ACElementProp_t AutoConnectUpdate::_elmResult[] PROGMEM = {
  { AC_Text, "status", nullptr, nullptr },
  { AC_Element, "restart", "<script type=\"text/javascript\">setTimeout(\"location.href='" AUTOCONNECT_URI "'\",1000*5);</script>", nullptr }
};
const AutoConnectUpdate::ACPage_t AutoConnectUpdate::_auxResult PROGMEM = {
  AUTOCONNECT_URI_UPDATE_RESULT, "Update", false, AutoConnectUpdate::_elmResult
};

#endif // _AUTOCONNECTUPDATEPAGE_H
