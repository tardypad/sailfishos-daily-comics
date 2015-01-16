/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

.pragma library

function browse(url)
{
    Qt.openUrlExternally(url)
}

function mail(email, subject, body)
{
    var subjectText = (subject !== undefined) ? subject : '';
    var bodyText    = (body !== undefined) ? body : '';

    Qt.openUrlExternally("mailto:"+email+"?subject="+subjectText+"&body="+bodyText)
}
