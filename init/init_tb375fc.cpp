#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;
using std::string;

void property_override(string prop, string value)
{
    auto pi = (prop_info *)__system_property_find(prop.c_str());
    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

void vendor_load_properties()
{
    string prop_partitions[] = {"", "vendor.", "odm."};
    for (const string &prop : prop_partitions)
    {
        property_override(string("ro.product.") + prop + string("brand"), "Lenovo");
        property_override(string("ro.product.") + prop + string("manufacturer"), "LENOVO");
        property_override(string("ro.product.") + prop + string("name"), "TB375FC_PRC");
        property_override(string("ro.product.") + prop + string("device"), "TB375FC");
        property_override(string("ro.product.") + prop + string("model"), "TB375FC");
        property_override(string("ro.product.") + prop + string("marketname"), "Lenovo xiaoxinpad 12.7 2025");
        property_override(string("ro.product.") + prop + string("cert"), "TB375FC");
    }
    property_override("ro.bootimage.build.date.utc", "1771967904");
    property_override("ro.build.date.utc", "1771967904");
    property_override("ro.build.fingerprint", "Lenovo/TB375FC_PRC/TB375FC:14/AP3A.240905.015/TB375FC_CN_OPEN_USER_M21.814_A16_ZUI_17.5.10.060_ST_260225:user/release-keys");
}
