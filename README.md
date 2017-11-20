# Zabbix module to monitor read-only ext4 filesystem

## How to build:

```
cd <zabbix-src> && ./configure
cd ./src/modules
git pull https://github.com/am813nt/zabbix-fs-ro
cd zabbix-fs-ro && make
```

## How to install:
```
Copy <zabbix-src>/src/modules/zabbix-fs-ro/fs_ro.so zabbix-agent's LoadModulePath
Add LoadModule=fs_ro.so to zabbix_agentd.conf
Restart zabbix-agent
```

## How to verify:
```
zabbix_agentd -t fs_ro.status
```

## Description
Key is `fs_ro.status`.
It returns 1 if there is ext4 read-only filesystem and 0 otherwise.




