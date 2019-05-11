function(page) {
    var regex = /src=&quot;([^&]*\/assets\/images\/[^&]*)&quot;/;
    var match = regex.exec(page);
    return match[1];
}
