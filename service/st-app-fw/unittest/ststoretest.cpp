#include <gtest/gtest.h>
#include <cstdlib>

extern "C"{
    #include "st_manager.h"
    #include "st_store.h"
    #include "st_cloud_manager.h"
    #include "port/oc_storage.h"
}

class TestSTStore: public testing::Test
{
    protected:
        virtual void SetUp()
        {

        }

        virtual void TearDown()
        {
            st_store_info_initialize();
        }
};

TEST_F(TestSTStore, st_store_load)
{
    int ret = st_store_load();
    EXPECT_EQ(0, ret);
}
/*
TEST_F(TestSTStore, st_store_dump)
{
    oc_storage_config("./st_things_creds");
    st_store_t *store_info = st_store_get_info();
    store_info->status = true;
    st_store_dump();
    st_store_info_initialize();
    st_store_load();

    EXPECT_EQ(true, store_info->status);
}
*/
TEST_F(TestSTStore, st_store_info_initialize)
{
    st_store_t *store_info = st_store_get_info();
    store_info->status = true;
    st_store_info_initialize();

    EXPECT_EQ(false, store_info->status);
}

TEST_F(TestSTStore, st_store_get_info)
{
    st_store_t *store_info = NULL;
    store_info = st_store_get_info();
    EXPECT_NE(NULL, store_info);
}