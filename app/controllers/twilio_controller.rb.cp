class TwilioController < ApplicationController
  
  def index
  	render :file => 'app/views/layouts/index.html.erb'
  end

  def send_sms
  	message = params[:message]
    subject = params[:subject]
  	number = params[:number]
  	account_sid = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'
  	auth_token = 'XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX'

  	@client = Twilio::REST::Client.new account_sid, auth_token

    # Sends SMS to single user
  	# @message = @client.account.messages.create({:to => "+1"+"#{number}",
  	# 															:from => "+1XXXXXXXXXX" # Replace with twilio number,
  	# 															:body => "SUBJ: "+"#{subject}"+"\n"+"MSG: "+"#{message}"})

    # Sends SMS to multiple users from file
    f = File.open("users.txt", "r")
    f.each_line do |line|
      number = line.split(";").last
      @message = @client.account.messages.create({:to => "+1"+"#{number}",
                                  :from => "+1XXXXXXXXXX" # Replace with twilio number,
                                  :body => "SUBJ: "+"#{subject}"+"\n"+"MSG: "+"#{message}"})
    end
    f.close

  	redirect_to '/'
  end

end
