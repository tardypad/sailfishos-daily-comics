function(page) {
    var regex = /src=&quot;([^&]*\/archive_b\/[^&]*)&quot;/;
    var match = regex.exec(page);
    return match[1];
}
