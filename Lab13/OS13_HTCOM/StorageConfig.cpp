#include "pch.h"
#include "StorageConfig.h"
#include "SharedMemory.h"
#include "Element.h"

StorageConfig::StorageConfig(const StorageConfig& storageConfig)
{
	this->capacity = storageConfig.capacity;
	this->maxKeyLength = storageConfig.maxKeyLength;
	this->maxPayloadLength = storageConfig.maxPayloadLength;
	this->secSnapshotInterval = storageConfig.secSnapshotInterval;
	strcpy_s(usersGroupName, USERS_GROUP_NAME_SIZE, storageConfig.usersGroupName);

	this->storageMemorySize = storageConfig.storageMemorySize;
	this->elementMemorySize = storageConfig.elementMemorySize;
}

StorageConfig::StorageConfig(int capacity,
	int secSnapshotInterval,
	int maxKeyLength,
	int maxPayloadLength,
	const char usersGroupName[USERS_GROUP_NAME_SIZE])
{
	this->capacity = capacity;
	this->maxKeyLength = maxKeyLength;
	this->maxPayloadLength = maxPayloadLength;
	this->secSnapshotInterval = secSnapshotInterval;
	strcpy_s(this->usersGroupName, USERS_GROUP_NAME_SIZE, usersGroupName);

	this->storageMemorySize = CalcStorageMaxSizeMemory();
	this->elementMemorySize = CalcElementMaxSizeMemory();
}

DWORD StorageConfig::CalcStorageMaxSizeMemory()
{
	DWORD elementSize = CalcElementMaxSizeMemory();
	return sizeof(StorageConfig) + sizeof(SharedMemory) + this->capacity * (elementSize);
}

DWORD StorageConfig::CalcElementMaxSizeMemory()
{
	return sizeof(Element) + this->maxKeyLength + this->maxPayloadLength;
}

int StorageConfig::getCapacity() const
{
	return capacity;
}

int StorageConfig::getMaxKeyLength() const
{
	return maxKeyLength;
}

int StorageConfig::getMaxPayloadLength() const
{
	return maxPayloadLength;
}

int StorageConfig::getSecSnapshotInterval() const
{
	return secSnapshotInterval;
}

DWORD StorageConfig::getStorageMemorySize() const
{
	return storageMemorySize;
}

DWORD StorageConfig::getElementMemorySize() const
{
	return elementMemorySize;
}