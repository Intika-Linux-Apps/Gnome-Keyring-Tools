import gnomekeyring

print gnomekeyring.get_info_sync(gnomekeyring.get_default_keyring_sync()).get_is_locked()


