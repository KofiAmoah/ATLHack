class TwilioController < ApplicationController
  
  def index
  	render :file => 'app/views/layouts/index.html.erb'
  end

  def send_sms
  	message = params[:message]
    subject = params[:subject]
  	number = params[:number]
  	account_sid = 'AC033a2b457424bb3af29cd54ea39644de'
  	auth_token = 'f88d97c71de5a9fd9463202ea75b88b6'

  	@client = Twilio::REST::Client.new account_sid, auth_token

  	@message = @client.account.messages.create({:to => "+1"+"#{number}",
  																:from => "+16147790912",
  																:body => "Subj: "+"#{subject}"+" "+"Msg: "+"#{message}"})
  	redirect_to '/'
  end

  # def send_verification
  #   number = params[:number]
  #   verification_code = (1000...9999).to_a.shuffle.first

  # end
end