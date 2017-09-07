// Copyright (c) 2017, Tencent Inc.
// All rights reserved.
//
// Author: sevenyou <sevenyou@tencent.com>
// Created: 07/21/17
// Description:

#ifndef BUCKET_RESP_H
#define BUCKET_RESP_H
#pragma once

#include <vector>

#include "cos_config.h"
#include "cos_defines.h"
#include "response/base_resp.h"

namespace qcloud_cos {

class PutBucketResp : public BaseResp {
public:
    PutBucketResp() {}
    virtual ~PutBucketResp() {}
};

class GetBucketResp : public BaseResp {
public:
    GetBucketResp() {}
    virtual ~GetBucketResp() {}

    virtual bool ParseFromXmlString(const std::string& body);

    /// \brief ��ȡBucket��Object��Ӧ��Ԫ��Ϣ
    std::vector<Content> GetContents() const { return m_contents; }

    /// \brief Bucket����
    std::string GetName() const { return m_name; }

    /// \brief ��ȡ�����
    std::string GetDelimiter() const { return m_delimiter; }

    /// \brief �����ʽ
    std::string GetEncodingType() const { return m_encoding_type; }

    /// \brief ���ص��ļ�ǰ׺
    std::string GetPrefix() const { return m_prefix; }

    /// \brief Ĭ����UTF-8������˳���г���Ŀ�������г���Ŀ��marker��ʼ
    std::string GetMarker() const { return m_marker; }

    /// \brief ������Ӧ�����ڷ��ؽ����������Ŀ����
    uint64_t GetMaxKeys() const { return m_max_keys; }

    /// \brief ��Ӧ������Ŀ�Ƿ񱻽ضϣ�����ֵ��true��false
    bool IsTruncated() const { return m_is_truncated; }

    /// \brief ���緵����Ŀ���ضϣ��򷵻� NextMarker ������һ����Ŀ�����
    std::string GetNextMarker() const { return m_next_marker; }

    /// \brief �� Prefix �� delimiter ֮�����ͬ·����Ϊһ�࣬����Ϊ Common Prefix
    std::vector<std::string> GetCommonPrefixes() const { return m_common_prefixes; }

private:
    std::vector<Content> m_contents;
    std::string m_name;
    std::string m_encoding_type;
    std::string m_delimiter;
    std::string m_prefix;
    std::string m_marker;
    uint64_t m_max_keys;
    bool m_is_truncated;
    std::string m_next_marker;
    std::vector<std::string> m_common_prefixes;
};

class GetBucketReplicationResp : public BaseResp {
public:
    GetBucketReplicationResp() {}
    virtual ~GetBucketReplicationResp() {}

    virtual bool ParseFromXmlString(const std::string& body);

    std::string GetRole() const { return m_role; }

    std::vector<ReplicationRule> GetRules() const { return m_rules; }

private:
    std::string m_role;
    std::vector<ReplicationRule> m_rules;
};

class PutBucketReplicationResp : public BaseResp {
public:
    PutBucketReplicationResp() {}
    virtual ~PutBucketReplicationResp() {}
};

class DeleteBucketReplicationResp : public BaseResp {
public:
    DeleteBucketReplicationResp() {}
    virtual ~DeleteBucketReplicationResp() {}

};
} // namespace qcloud_cos
#endif // BUCKET_RESP_H
